/*
 * Copyright 2014 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Author: morlovich@google.com (Maksim Orlovich)

#include "pagespeed/system/system_rewrite_options.h"

#include <functional>

#include "net/instaweb/rewriter/public/rewrite_options_test_base.h"
#include "pagespeed/kernel/base/google_message_handler.h"
#include "pagespeed/kernel/base/gtest.h"
#include "pagespeed/kernel/base/null_thread_system.h"
#include "pagespeed/kernel/base/scoped_ptr.h"

namespace net_instaweb {

class SystemRewriteOptionsTest
    : public RewriteOptionsTestBase<SystemRewriteOptions> {
 protected:
  SystemRewriteOptionsTest() : options_("test", &thread_system_) {
  }

  // Helper for testing options consisting of single integer. Validates that
  // setting an option with option_name changes return value of getter and that
  // errors are reported on incorrect values.
  void TestIntOption(const char* option_name,
                     std::function<int(SystemRewriteOptions*)> getter) {
    GoogleString msg;
    RewriteOptions::OptionSettingResult result =
        options_.ParseAndSetOptionFromName1(
            option_name, "1234", &msg,
            &handler_);
    EXPECT_EQ(result, RewriteOptions::kOptionOk);
    EXPECT_EQ(1234, getter(&options_));
    EXPECT_EQ("", msg);

    result = options_.ParseAndSetOptionFromName1(
        option_name, "1a", &msg, &handler_);
    EXPECT_EQ(result, RewriteOptions::kOptionValueInvalid);
    EXPECT_EQ(1234, getter(&options_));
    EXPECT_NE("", msg);
  }

  NullThreadSystem thread_system_;
  GoogleMessageHandler handler_;
  SystemRewriteOptions options_;
};

TEST_F(SystemRewriteOptionsTest, StaticAssetCdn) {
  // Check parsing.
  EXPECT_FALSE(options_.has_static_assets_to_cdn());

  GoogleString msg;
  RewriteOptions::OptionSettingResult result =
      options_.ParseAndSetOptionFromName1(
        SystemRewriteOptions::kStaticAssetCDN, "foo.com", &msg, &handler_);
  EXPECT_EQ(result, RewriteOptions::kOptionValueInvalid);
  EXPECT_EQ("Cannot set option StaticAssetCDN to foo.com. "
            "Not enough arguments.", msg);
  EXPECT_FALSE(options_.has_static_assets_to_cdn());

  result = options_.ParseAndSetOptionFromName1(
      SystemRewriteOptions::kStaticAssetCDN, "foo.com, Weird", &msg, &handler_);
  EXPECT_EQ(result, RewriteOptions::kOptionValueInvalid);
  EXPECT_EQ("Cannot set option StaticAssetCDN to foo.com, Weird. "
            "Invalid static asset label: Weird",
            msg);
  EXPECT_FALSE(options_.has_static_assets_to_cdn());

  result = options_.ParseAndSetOptionFromName1(
      SystemRewriteOptions::kStaticAssetCDN,
      "//foo.com, ADD_INSTRUMENTATION_JS, BLANK_GIF", &msg, &handler_);
  EXPECT_EQ(result, RewriteOptions::kOptionOk) << msg;
  EXPECT_TRUE(options_.has_static_assets_to_cdn());
  EXPECT_EQ("//foo.com", options_.static_assets_cdn_base());
  const SystemRewriteOptions::StaticAssetSet& assets =
      options_.static_assets_to_cdn();
  EXPECT_EQ(2, assets.size());
  EXPECT_TRUE(assets.find(StaticAssetEnum::ADD_INSTRUMENTATION_JS) !=
              assets.end());
  EXPECT_TRUE(assets.find(StaticAssetEnum::BLANK_GIF) !=
              assets.end());

  // Check conversion into proto.
  StaticAssetConfig proto_conf;
  options_.FillInStaticAssetCDNConf(&proto_conf);
  ASSERT_EQ(2, proto_conf.asset_size());
  const StaticAssetConfig::Asset& a1 = proto_conf.asset(0);
  EXPECT_EQ(StaticAssetEnum::ADD_INSTRUMENTATION_JS, a1.role());
  EXPECT_EQ("add_instrumentation.js", a1.name());
  EXPECT_EQ("opt", a1.opt_hash());
  EXPECT_EQ("dbg", a1.debug_hash());

  const StaticAssetConfig::Asset& a2 = proto_conf.asset(1);
  EXPECT_EQ(StaticAssetEnum::BLANK_GIF, a2.role());
  EXPECT_EQ("blank.gif", a2.name());
  EXPECT_EQ("opt", a2.opt_hash());
  EXPECT_EQ("dbg", a2.debug_hash());

  // Test merging.

  // Merge of something w/o these options.
  scoped_ptr<SystemRewriteOptions> options2(
      new SystemRewriteOptions(&thread_system_));
  options_.Merge(*options2);

  EXPECT_TRUE(options_.has_static_assets_to_cdn());
  EXPECT_EQ("//foo.com", options_.static_assets_cdn_base());

  const SystemRewriteOptions::StaticAssetSet& assets2 =
      options_.static_assets_to_cdn();
  EXPECT_EQ(2, assets2.size());
  EXPECT_TRUE(assets2.find(StaticAssetEnum::ADD_INSTRUMENTATION_JS) !=
              assets2.end());
  EXPECT_TRUE(assets2.find(StaticAssetEnum::BLANK_GIF) !=
              assets2.end());

  // Merge of something with the same path --- overwrites both.
  scoped_ptr<SystemRewriteOptions> options3(
      new SystemRewriteOptions(&thread_system_));
  result = options3->ParseAndSetOptionFromName1(
      SystemRewriteOptions::kStaticAssetCDN,
      "//foo.com, BLANK_GIF, MOBILIZE_JS", &msg, &handler_);
  ASSERT_EQ(result, RewriteOptions::kOptionOk) << msg;

  options_.Merge(*options3);
  EXPECT_TRUE(options_.has_static_assets_to_cdn());
  EXPECT_EQ("//foo.com", options_.static_assets_cdn_base());
  const SystemRewriteOptions::StaticAssetSet& assets3 =
      options_.static_assets_to_cdn();
  EXPECT_EQ(2, assets3.size());
  EXPECT_TRUE(assets3.find(StaticAssetEnum::BLANK_GIF) != assets3.end());
  EXPECT_TRUE(assets3.find(StaticAssetEnum::MOBILIZE_JS) != assets3.end());

  // Merge of something with different path --- overwrites as well.
  scoped_ptr<SystemRewriteOptions> options4(
      new SystemRewriteOptions(&thread_system_));
  result = options4->ParseAndSetOptionFromName1(
      SystemRewriteOptions::kStaticAssetCDN,
      "//bar.com, MOBILIZE_JS", &msg, &handler_);
  ASSERT_EQ(result, RewriteOptions::kOptionOk) << msg;

  options_.Merge(*options4);
  EXPECT_TRUE(options_.has_static_assets_to_cdn());
  EXPECT_EQ("//bar.com", options_.static_assets_cdn_base());
  const SystemRewriteOptions::StaticAssetSet& assets4 =
      options_.static_assets_to_cdn();
  EXPECT_EQ(1, assets4.size());
  EXPECT_TRUE(assets4.find(StaticAssetEnum::MOBILIZE_JS) != assets4.end());
}

TEST_F(SystemRewriteOptionsTest, CentralControllerInitValue) {
  EXPECT_EQ(0, options_.controller_port());
}

TEST_F(SystemRewriteOptionsTest, CentralController) {
  TestIntOption(SystemRewriteOptions::kCentralControllerPort,
                &SystemRewriteOptions::controller_port);
}

TEST_F(SystemRewriteOptionsTest, RedisServerEmptyByDefault) {
  EXPECT_TRUE(options_.redis_server().empty());
}

TEST_F(SystemRewriteOptionsTest, RedisServerHostPort) {
  GoogleString msg;
  RewriteOptions::OptionSettingResult result =
      options_.ParseAndSetOptionFromName1(
          SystemRewriteOptions::kRedisServer, "example.com:1234", &msg,
          &handler_);
  EXPECT_EQ(result, RewriteOptions::kOptionOk);
  EXPECT_EQ("example.com", options_.redis_server().host);
  EXPECT_EQ(1234, options_.redis_server().port);
  EXPECT_EQ("", msg);
}

TEST_F(SystemRewriteOptionsTest, RedisServerHostOnly) {
  GoogleString msg;
  RewriteOptions::OptionSettingResult result =
      options_.ParseAndSetOptionFromName1(
          SystemRewriteOptions::kRedisServer, "example.com", &msg,
          &handler_);
  EXPECT_EQ(result, RewriteOptions::kOptionOk);
  EXPECT_EQ("example.com", options_.redis_server().host);
  EXPECT_EQ(SystemRewriteOptions::RedisServerSpec::kDefaultPort,
            options_.redis_server().port);
  EXPECT_EQ("", msg);
}

class SystemRewriteOptionsInvalidRedisServerTest
    : public SystemRewriteOptionsTest {
 public:
  void TestInvalidSpec(const GoogleString &spec) {
    GoogleString msg;
    options_.ParseAndSetOptionFromName1(SystemRewriteOptions::kRedisServer,
                                        "example.com:1234", &msg, &handler_);

    RewriteOptions::OptionSettingResult result =
        options_.ParseAndSetOptionFromName1(
            SystemRewriteOptions::kRedisServer, spec, &msg,
            &handler_);
    EXPECT_EQ(result, RewriteOptions::kOptionValueInvalid);
    EXPECT_EQ("example.com", options_.redis_server().host);
    EXPECT_EQ(1234, options_.redis_server().port);
    EXPECT_NE("", msg);
  }
};

TEST_F(SystemRewriteOptionsInvalidRedisServerTest, NonNumericPort) {
  TestInvalidSpec("host:1port");
}

TEST_F(SystemRewriteOptionsInvalidRedisServerTest, InvalidPortNumber1) {
  TestInvalidSpec("host:0");
}

TEST_F(SystemRewriteOptionsInvalidRedisServerTest, InvalidPortNumber2) {
  TestInvalidSpec("host:100000");
}

TEST_F(SystemRewriteOptionsInvalidRedisServerTest, MultipleColons) {
  TestInvalidSpec("host:10:20");
}

TEST_F(SystemRewriteOptionsTest, RedisReconnectionDelayInitValue) {
  EXPECT_GT(options_.redis_reconnection_delay_ms(), 0);
}

TEST_F(SystemRewriteOptionsTest, RedisReconnectionDelay) {
  TestIntOption(SystemRewriteOptions::kRedisReconnectionDelayMs,
                &SystemRewriteOptions::redis_reconnection_delay_ms);
}

TEST_F(SystemRewriteOptionsTest, RedisTimeoutInitValue) {
  EXPECT_GT(options_.redis_timeout_us(), 0);
}

TEST_F(SystemRewriteOptionsTest, RedisTimeout) {
  TestIntOption(SystemRewriteOptions::kRedisTimeoutUs,
                &SystemRewriteOptions::redis_timeout_us);
}

}  // namespace net_instaweb
