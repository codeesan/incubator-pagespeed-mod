(function(){var aa=encodeURIComponent,e=window,f=Object,g=document,ba=navigator;function h(a,b){return a.createElement=b}function k(a,b){return a.deferJs=b}function l(a,b){return a.attachEvent=b}function p(a,b){return a.addEventListener=b}
var r="exec",s="insertBefore",t="querySelector",u="defineProperty",v="setAttribute",w="deferJs",x="attachEvent",y="getElementsByTagName",z="documentElement",A="registerScriptTags",B="fireEvent",C="execute",D="push",E="item",F="indexOf",G="hasAttribute",H="readyState",I="addEventListener",J="name",K="length",L="prototype",M="body",N="removeChild",O="call",P="getAttribute",Q="querySelectorAll",R="parentNode",S="",ca="\n",da='");',ea='"]',fa="*",ga=":not([",ha="<div>_</div>",ia='=document.getElementById("',
ja="Add to queue str: ",ka="Add to queue url: ",la="AppleWebKit",ma="DOMContentLoaded",na="Evaluated: ",oa="Exception while evaluating.",pa="Exception while overriding document.all.",qa="Exception while overriding document.readyState.",ra="Executed: ",sa="Executing a script twice. Orig_Index: ",ta="Firefox",ua="Firing Event: ",va="Function is not defined",wa="PSA ERROR: ",xa="SCRIPT",ya="Unable to insert nodes, no context element found",za="[",Aa="[data-pagespeed-onload][data-pagespeed-loaded]",Ba=
"[psa_current_node]",Ca="[psa_to_be_deleted]",Da='[type="',Ea="]",Fa="])",Ga="all",Ha="application/ecmascript",Ia="application/javascript",Ja="application/x-ecmascript",Ka="application/x-javascript",La="async",Ma="complete",Na="data-pagespeed-onload",Oa="data:text/javascript,",Pa="defer",Qa="div",Ra="dw: ",Sa="error",Ta="function",Ua="handle_dw: ",Va="id",Wa="interactive",Xa="language",Ya="load",Za="loaded",$a="loading",ab="on",bb="onDOMContentLoaded",cb="onafterscripts",db="onbeforescripts",eb="onload",
fb="onreadystatechange",gb="orig_index",hb="pagespeed_orig_src",ib="pagespeed_orig_type",jb="priority_psa_not_processed",kb="psa_current_node",lb="psa_dw_target",mb="psa_not_processed",nb="psa_prefetch_container",ob="psa_to_be_deleted",pb="psanode",qb="readyState",rb="readystatechange",T="script",sb="src",tb="text/",ub="text/ecmascript",vb="text/javascript",wb="text/javascript1.0",xb="text/javascript1.1",yb="text/javascript1.2",zb="text/javascript1.3",Ab="text/javascript1.4",Bb="text/javascript1.5",
Cb="text/jscript",Db="text/livescript",Eb="text/prioritypsajs",Fb="text/psajs",Gb="text/x-ecmascript",Hb="text/x-javascript",Ib="true",U="type",Jb="var ",Kb="var psaFunc=function() {",Lb="window.pagespeed.psatemp=0;",Mb="};",V,W=function(a,b,c){if(a[I])a[I](b,c,!1);else if(a[x])a[x](ab+b,c);else{var d=a[ab+b];a[ab+b]=function(){c[O](this);d&&d[O](this)}}};e.pagespeed=e.pagespeed||{};var X=e.pagespeed;X.deferJsNs={};var Y=X.deferJsNs,Z=function(){this.n=[];this.m=[];this.q=this.l=0;this.r=[];this.i=S;this.v={};this.O=[Ha,Ia,Ja,Ka,ub,vb,wb,xb,yb,zb,Ab,Bb,Cb,Db,Gb,Hb];this.J=g.getElementById;this.p=g[y];this.ga=g.write;this.ha=g.writeln;this.fa=g.open;this.ea=g.close;this.M=g[I];this.K=e[I];this.N=g[x];this.L=e[x];this.d=g.createElement;this.C=this.a=0;this.k=this.B=!0;this.e=null;this.t=0;this.u=[];this.c=this.g=S;this.s=-1},Nb=!1;V=Z[L];
V.log=function(a,b){this.m&&(this.m[D](S+a),b&&(this.m[D](b),"undefined"!=typeof console&&"undefined"!=typeof console.log&&console.log(wa+a+b.message)))};V.V=function(a,b){this.n.splice(b?b:this.n[K],0,a)};V.Y=function(a,b){var c=this.W(b);c.text=a;c[v](U,vb);var d=this.A();d[R][s](c,d);return c};
V.ka=function(){for(var a=g[y](fa),b=S,c=0;c<a[K];c++)if(a[c][G](Va)){var d=a[c][P](Va);if(d&&-1==d.search(/[-:.]/)&&-1==d.search(/^[0-9]/))try{e[d]&&e[d].tagName&&(b+=Jb+d+ia+d+da)}catch(q){this.log(oa,q)}}b&&(a=this.Y(b),a[v](mb,S),a[v](jb,S))};V.xa=function(a){this.Da()&&((new Image).src=a)};V.H=function(a,b,c){var d=a[P](hb)||a[P](sb);d?(c&&this.xa(d),this.addUrl(d,a,b)):this.ca(a.innerHTML||a.textContent||a.data||S,a,b)};
V.ca=function(a,b,c){if(this.oa())this.addUrl(Oa+aa(a),b,c);else{this.m[D](ja+a);var d=this;this.V(function(){d.G(b);d.U()[v](kb,S);try{d.Y(a,b)}catch(c){d.log(oa,c)}d.log(na+a);d.w()},c)}};Z[L].addStr=Z[L].ca;Z[L].W=function(a){var b=this.d[O](g,T);if(a)for(var c=a.attributes,d=c[K]-1;0<=d;--d)c[d][J]!=U&&c[d][J]!=sb&&c[d][J]!=La&&c[d][J]!=Pa&&c[d][J]!=ib&&c[d][J]!=hb&&c[d][J]!=gb&&c[d][J]!=kb&&c[d][J]!=this.c&&(b[v](c[d][J],c[d].value),a.removeAttribute(c[d][J]));return b};
Z[L].na=function(a){var b=this.d[O](g,T);b[v](U,vb);b.async=!1;b[v](ob,S);b[v](mb,S);b[v](jb,S);var c=this,d=function(){if(g[t]){var b=g[t](Ca);b&&b[R][N](b)}c.log(ra+a);c.w()};Y.h(b,d);W(b,Sa,d);b.src=Oa+aa(Lb);d=this.A();d[R][s](b,d)};
Z[L].addUrl=function(a,b,c){this.m[D](ka+a);var d=this;this.V(function(){d.G(b);var c=d.W(b);c[v](U,vb);var m=!1;La in c?(m=!0,c.async=!1):c[H]&&W(c,rb,function(){if(c[H]==Ma||c[H]==Za)c.onreadystatechange=null,d.log(ra+a),d.w()});c[v](sb,a);var n=b.innerHTML||b.textContent||b.data;n&&c.appendChild(g.createTextNode(n));n=d.U();n[v](kb,S);n[R][s](c,n);m&&d.na(a)},c)};Z[L].addUrl=Z[L].addUrl;V=Z[L];
V.G=function(a){if(g[Q]&&!(8>=this.b()))for(var b=g[Q](za+this.c+Ea),c=0;c<b[K];c++){var d=b[E](c);if(d==a)break;d[P](U)!=this.g&&d.removeAttribute(this.c)}};V.$=function(){for(var a=this.p[O](g,fa),b=0;b<a[K];b++)a[E](b)[v](this.c,S)};V.U=function(){var a=null;g[t]&&(a=g[t](Da+this.g+ea));return a};V.A=function(){var a;g[t]&&(a=g[t](Ba));return a||this.p[O](g,pb)[0]};V.la=function(){var a=this.A();a.nodeName==xa&&a[R][N](a)};
V.D=function(){if(!(5<=this.a))if(this.k&&this.j()&&(this.b()&&g[z].originalDoScroll&&(g[z].doScroll=g[z].originalDoScroll),f[u]&&delete g[H],this.b()&&f[u]&&delete g.all),g.getElementById=this.J,!g[Q]||8>=this.b()||(g.getElementsByTagName=this.p),h(g,this.d),g.open=this.fa,g.close=this.ea,g.write=this.ga,g.writeln=this.ha,this.k)if(this.a=5,this.ia(),this.j()){var a=this;g[H]!=Ma?Y.h(e,function(){a.F()}):(g.onreadystatechange&&this[r](g.onreadystatechange,g),e.onload&&($(e,eb,e.onload),e.onload=
null),this.F())}else this.R();else this.a=1,this.B=!1,this.e&&this.j()?(k(X,X.f),k(X,X.f),this[r](this.e),this.e=null):this.R()};V.F=function(){this.j()&&(this.ma(),X.f.F());this[B](3);if(this.j()){for(var a=g[M][y](pb),b=a[K]-1;0<=b;b--)g[M][N](a[b]);a=g[M].getElementsByClassName(nb);for(b=a[K]-1;0<=b;b--)a[b][R][N](a[b])}this.a=6;this[B](4)};V.R=function(){var a=this;e.setTimeout(function(){k(X,X.o);k(X,X.o);if(a.e)X[w][A](a.e,a.s),a.e=null;else X[w][A]();X[w][C]()},0)};
V.ta=function(a){for(;a=a[R];)if(a==g)return!0;return!1};V.T=function(a){for(var b=0,c=a[K],d=0;d<c;++d){var q=a[d],m=q[R],n=q.src,Ob=q.textContent;(8<this.b()&&(!m||n==S&&Ob==S)||!(this.b()||this.ta(q)&&n!=S))&&b++}return b};V.P=function(){if(4!=this.a)return!1;var a=0;0!=this.q&&(a=this.T(this.r));return this.q==a?!0:!1};V.Ea=function(){return 6===this.a};Z[L].scriptsAreDone=Z[L].Ea;
Z[L].w=function(){this.Q();this.la();this.l<this.n[K]?(this.l++,this.n[this.l-1][O](e)):this.k?(this.a=4,this.G(),this[B](2),this.P()&&this.D()):this.D()};Z[L].Z=function(a){for(var b=[],c=a[K],d=0;d<c;++d)b[D](a[E](d));return b};
Z[L].qa=function(){var a=this;if(this.B&&!this.j()){var b=g.createElement(pb);b[v](lb,Ib);g[M].appendChild(b);this.b()&&this.ka();if(f[u])try{var c={configurable:!0,get:function(){return 4<=a.a?Wa:$a}};f[u](g,qb,c)}catch(d){this.log(qa,d)}if(this.b()&&(g[z].originalDoScroll=g[z].doScroll,g[z].doScroll=function(){throw"psa exception";},f[u]))try{c={configurable:!0,get:function(){}},f[u](g,Ga,c)}catch(q){this.log(pa,q)}}this.ja();g.writeln=function(b){a.S(b+ca)};g.write=function(b){a.S(b)};g.open=function(){};
g.close=function(){};g.getElementById=function(b){a.Q();b=a.J[O](g,b);return null==b||b[G](a.c)?null:b};!g[Q]||8>=a.b()||(g.getElementsByTagName=function(b){try{return g[Q](b+ga+a.c+Fa)}catch(c){return a.p[O](g,b)}});h(g,function(b){var c=a.d[O](g,b);b.toLowerCase()==T&&(a.r[D](c),a.q++,b=function(){a.q--;var b=a.r[F](this);-1!=b&&(a.r.splice(b,1),a.P()&&a.D())},Y.h(c,b),W(c,Sa,b));return c})};Z[L].execute=function(){if(2==this.a){var a=0;0!=this.t&&(a=this.T(this.u));this.t==a&&(h(g,this.d),this.run())}};
Z[L].execute=Z[L][C];Z[L].run=function(){2==this.a&&(this.B&&this[B](1),this.a=3,this.qa(),this.w())};Z[L].run=Z[L].run;V=Z[L];V.wa=function(a){var b=this.d[O](g,Qa);b.innerHTML=ha+a;b[N](b.firstChild);return b};V.ya=function(a){var b=a[R];b&&b[N](a)};V.va=function(a,b){for(var c=this.Z(a),d=c[K],q=b[R],m=0;m<d;++m){var n=c[m];this.ya(n);q[s](n,b)}};V.ra=function(a){return a.nodeName!=xa?!1:a[G](U)?(a=a[P](U),!a||-1!=this.O[F](a)):a[G](Xa)?(a=a[P](Xa),!a||-1!=this.O[F](tb+a.toLowerCase())):!0};
V.X=function(a,b){if(a.childNodes)for(var c=this.Z(a.childNodes),d=c[K],q=0;q<d;++q){var m=c[q];m.nodeName==xa?this.ra(m)&&(b[D](m),m[v](ib,m.type),m[v](U,this.g),m[v](hb,m.src),m[v](sb,S),m[v](this.c,S)):this.X(m,b)}};V.ua=function(a,b){for(var c=a[K],d=0;d<c;++d)this.H(a[d],b+d,!!d)};V.sa=function(a,b,c){a=this.wa(a);var d=[];this.X(a,d);c?this.va(a.childNodes,c):this.log(ya);this.ua(d,b)};V.Q=function(){if(this.i!=S){this.log(Ua+this.i);var a=this.i;this.i=S;var b=this.A();this.sa(a,this.l,b)}};
V.S=function(a){this.log(Ra+a);this.i+=a};V.ma=function(){var a;g[Q]&&(a=g[Q](Aa));for(var b=0;b<a[K];b++){var c=a[E](b),d=Kb+c[P](Na)+Mb;e.eval[O](e,d);typeof e.psaFunc!=Ta?this.log(va,Error(S)):$(c,eb,e.psaFunc)}};V.Aa=function(a){$(e,db,a)};Z[L].addBeforeDeferRunFunctions=Z[L].Aa;Z[L].za=function(a){$(e,cb,a)};Z[L].addAfterDeferRunFunctions=Z[L].za;Z[L].fireEvent=function(a){this.C=a;this.log(ua+a);a=this.v[a]||[];for(var b=0;b<a[K];++b)this[r](a[b]);a.length=0};
Z[L].exec=function(a,b){try{a[O](b||e)}catch(c){this.log(oa,c)}};Z[L].ja=function(){var a=this;e[I]?(p(g,function(b,c,d){$(g,b,c,d,a.M)}),p(e,function(b,c,d){$(e,b,c,d,a.K)})):e[x]&&(l(g,function(b,c){$(g,b,c,void 0,a.N)}),l(e,function(b,c){$(e,b,c,void 0,a.L)}))};Z[L].ia=function(){e[I]?(p(g,this.M),p(e,this.K)):e[x]&&(l(g,this.N),l(e,this.L))};
var $=function(a,b,c,d,q){var m=X[w];if(!(6<=m.a)){var n;if(2>m.C&&(b==ma||b==rb||b==bb||b==fb))b=2,n=ma;else if(3>m.C&&(b==Ya||b==eb))b=3,n=Ya;else if(b==db)b=1;else if(b==cb)b=4;else{q&&q[O](a,b,c,d);return}m.v[b]||(m.v[b]=[]);m.v[b][D](function(){var b={bubbles:!1,cancelable:!1,eventPhase:2};b.timeStamp=(new Date).getTime();b.type=n;b.target=a!=e?a:g;b.currentTarget=a;c[O](a,b)})}};
Z[L].registerScriptTags=function(a,b){if(!(2<=this.a)){if(a){if(!Nb){a();return}this.k=!1;this.e=a;b&&(this.s=b)}else this.k=!0;this.a=2;for(var c=g[y](T),d=c[K],q=0;q<d;++q){var m=this.n[K]==this.l,n=c[q];n[P](U)==this.g&&(a?n[P](gb)<=this.s&&this.H(n,void 0,!m):(n[P](gb)<this.s&&this.log(sa+n[P](gb),Error(S)),this.H(n,void 0,!m)))}}};Z[L].registerScriptTags=Z[L][A];Y.h=function(a,b){W(a,Ya,b)};X.addOnload=Y.h;V=Z[L];V.oa=function(){return-1!=ba.userAgent[F](ta)};V.Da=function(){return-1!=ba.userAgent[F](la)};
V.b=function(){var a=/(?:MSIE.(\d+\.\d+))/[r](ba.userAgent);return a&&a[1]?g.documentMode||parseFloat(a[1]):NaN};V.ba=function(a){this.g=a};V.aa=function(a){this.c=a};V.j=function(){return this.g==Fb?!0:!1};V.pa=function(){var a=this;h(g,function(b){var c=a.d[O](g,b);b.toLowerCase()==T&&(a.u[D](c),a.t++,b=function(){var b=a.u[F](this);-1!=b&&(a.u.splice(b,1),a.t--,a[C]())},Y.h(c,b),W(c,Sa,b));return c})};V.Ca=function(){return Nb};Z[L].isExperimentalMode=Z[L].Ca;
Y.Ba=function(){X[w]||(Nb=X.defer_js_experimental,X.f=new Z,X.f.ba(Eb),X.f.aa(jb),X.f.$(),X.o=new Z,X.o.ba(Fb),X.o.aa(mb),X.o.$(),k(X,X.f),X[w].pa(),k(X,X[w]))};Y.Ba();X.da=!1;Y.I=function(){X.da||X.panelLoader||(X.da=!0,X[w][A](),X[w][C]())};Y.startDeferJs=Y.I;W(g,ma,Y.I);Y.h(e,Y.I);})();
