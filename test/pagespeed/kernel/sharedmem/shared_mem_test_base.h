/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef PAGESPEED_KERNEL_SHAREDMEM_SHARED_MEM_TEST_BASE_H_
#define PAGESPEED_KERNEL_SHAREDMEM_SHARED_MEM_TEST_BASE_H_

#include <cstddef>

#include "pagespeed/kernel/base/abstract_shared_mem.h"
#include "pagespeed/kernel/base/basictypes.h"
#include "pagespeed/kernel/base/scoped_ptr.h"
#include "test/pagespeed/kernel/base/gtest.h"
#include "test/pagespeed/kernel/base/mock_message_handler.h"

namespace net_instaweb {

class Function;
class ThreadSystem;

class SharedMemTestEnv {
 public:
  virtual ~SharedMemTestEnv();
  SharedMemTestEnv() {}

  virtual AbstractSharedMem* CreateSharedMemRuntime() = 0;

  // This method must be overridden to start a new process and invoke the
  // callback object in it. The runtime is responsible for deleting the callback
  // object properly.
  //
  // Returns whether started OK or not.
  virtual bool CreateChild(Function* callback) = 0;

  // This method must be overridden to block until all processes/threads started
  // by CreateChild exit.
  virtual void WaitForChildren() = 0;

  // Runtime-specific short sleep.
  virtual void ShortSleep() = 0;

  // Called in a child to denote it exiting with failure
  virtual void ChildFailed() = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(SharedMemTestEnv);
};

class SharedMemTestBase : public testing::Test {
 protected:
  typedef void (SharedMemTestBase::*TestMethod)();

  explicit SharedMemTestBase(SharedMemTestEnv* test_env);

  bool CreateChild(TestMethod method);

  // Basic read/write operation test.
  void TestReadWrite(bool reattach);

  // Test with large data; also test initialization.
  void TestLarge();

  // Make sure that 2 segments don't interfere.
  void TestDistinct();

  // Make sure destruction destroys things properly...
  void TestDestroy();

  // Make sure that re-creating a segment without a Destroy is safe and
  // produces a distinct segment.
  void TestCreateTwice();

  // Make sure between two kids see the SHM as well.
  void TestTwoKids();

  // Test for mutex operation.
  void TestMutex();

 private:
  static const int kLarge = 0x1000 - 4;  // not a multiple of any page size, but
                                         // a multiple of 4.
  static const int kNumIncrements = 0xFFFFF;

  volatile int* IntPtr(AbstractSharedMemSegment* seg, int offset) {
    return reinterpret_cast<volatile int*>(&seg->Base()[offset]);
  }

  AbstractSharedMemSegment* CreateDefault();
  AbstractSharedMemSegment* AttachDefault();
  AbstractMutex* AttachDefaultMutex(AbstractSharedMemSegment* segment);

  void DestroyDefault();

  // writes '1' to the default segment's base location.
  void WriteSeg1Child();

  // writes '2' to the other segment's base location.
  void WriteSeg2Child();

  void TestReadWriteChild();
  void TestLargeChild();
  void TwoKidsChild1();
  void TwoKidsChild2();

  bool IncrementStorm(AbstractSharedMemSegment* seg, size_t mutex_size);

  void MutexChild();

  std::unique_ptr<SharedMemTestEnv> test_env_;
  std::unique_ptr<AbstractSharedMem> shmem_runtime_;
  std::unique_ptr<ThreadSystem> thread_system_;
  MockMessageHandler handler_;

  DISALLOW_COPY_AND_ASSIGN(SharedMemTestBase);
};

// Passes in the SharedMemTestEnv to SharedMemTestBase via a template param
// to help glue us to the test framework
template <typename ConcreteTestEnv>
class SharedMemTestTemplate : public SharedMemTestBase {
 public:
  SharedMemTestTemplate() : SharedMemTestBase(new ConcreteTestEnv) {}
};

TYPED_TEST_SUITE_P(SharedMemTestTemplate);

TYPED_TEST_P(SharedMemTestTemplate, TestRewrite) {
  SharedMemTestBase::TestReadWrite(false);
}

TYPED_TEST_P(SharedMemTestTemplate, TestRewriteReattach) {
  SharedMemTestBase::TestReadWrite(true);
}

TYPED_TEST_P(SharedMemTestTemplate, TestLarge) {
  SharedMemTestBase::TestLarge();
}

TYPED_TEST_P(SharedMemTestTemplate, TestDistinct) {
  SharedMemTestBase::TestDistinct();
}

TYPED_TEST_P(SharedMemTestTemplate, TestDestroy) {
  SharedMemTestBase::TestDestroy();
}

TYPED_TEST_P(SharedMemTestTemplate, TestCreateTwice) {
  SharedMemTestBase::TestCreateTwice();
}

TYPED_TEST_P(SharedMemTestTemplate, TestTwoKids) {
  SharedMemTestBase::TestTwoKids();
}

TYPED_TEST_P(SharedMemTestTemplate, TestMutex) {
  SharedMemTestBase::TestMutex();
}

REGISTER_TYPED_TEST_SUITE_P(SharedMemTestTemplate, TestRewrite,
                            TestRewriteReattach, TestLarge, TestDistinct,
                            TestDestroy, TestCreateTwice, TestTwoKids,
                            TestMutex);

GTEST_ALLOW_UNINSTANTIATED_PARAMETERIZED_TEST(SharedMemTestTemplate);

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_SHAREDMEM_SHARED_MEM_TEST_BASE_H_
