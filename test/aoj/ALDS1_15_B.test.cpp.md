---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: io/precision.cpp
    title: io/precision.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-6
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_15_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"io/precision.cpp\"\n\n#line 3 \"io/precision.cpp\"\nusing namespace\
    \ std;\n#endif\n//BEGIN CUT HERE\nstruct Precision{\n  Precision(){\n    cout<<fixed<<setprecision(12);\n\
    \  }\n}precision_beet;\n//END CUT HERE\n#ifndef call_from_test\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/aoj/ALDS1_15_B.test.cpp\"\n#undef call_from_test\n\
    \n#define ERROR \"1e-6\"\n\nsigned main(){\n  using D = double;\n\n  int n,w;\n\
    \  cin>>n>>w;\n  vector<D> vs(n),ws(n);\n  for(int i=0;i<n;i++) cin>>vs[i]>>ws[i];\n\
    \n  using P = pair<D, int>;\n  vector<P> vp;\n  for(int i=0;i<n;i++)\n    vp.emplace_back(vs[i]/ws[i],i);\n\
    \n  sort(vp.rbegin(),vp.rend());\n\n  D ans=0,res=w;\n  for(auto p:vp){\n    D\
    \ amount=min(ws[p.second],res);\n    res-=amount;\n    ans+=amount*p.first;\n\
    \  }\n\n  cout<<ans<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_15_B\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../io/precision.cpp\"\n#undef call_from_test\n\n#define ERROR \"\
    1e-6\"\n\nsigned main(){\n  using D = double;\n\n  int n,w;\n  cin>>n>>w;\n  vector<D>\
    \ vs(n),ws(n);\n  for(int i=0;i<n;i++) cin>>vs[i]>>ws[i];\n\n  using P = pair<D,\
    \ int>;\n  vector<P> vp;\n  for(int i=0;i<n;i++)\n    vp.emplace_back(vs[i]/ws[i],i);\n\
    \n  sort(vp.rbegin(),vp.rend());\n\n  D ans=0,res=w;\n  for(auto p:vp){\n    D\
    \ amount=min(ws[p.second],res);\n    res-=amount;\n    ans+=amount*p.first;\n\
    \  }\n\n  cout<<ans<<endl;\n  return 0;\n}\n"
  dependsOn:
  - io/precision.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_15_B.test.cpp
  requiredBy: []
  timestamp: '2020-08-07 15:47:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_15_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_15_B.test.cpp
- /verify/test/aoj/ALDS1_15_B.test.cpp.html
title: test/aoj/ALDS1_15_B.test.cpp
---