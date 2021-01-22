---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.quickfind.test.cpp
    title: test/aoj/DSL_1_A.quickfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructure/quickfind.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n#endif\n//BEGIN CUT HERE\nstruct QuickFind{\n  vector<int>\
    \ rs,ps;\n  vector< vector<int> > vs;\n  QuickFind(int n):rs(n,1),ps(n),vs(n){\n\
    \    iota(ps.begin(),ps.end(),0);\n    for(int i=0;i<n;i++) vs[i].assign(1,i);\n\
    \  }\n  int find(int x) const{return ps[x];}\n  bool same(int x,int y) const{\n\
    \    return find(x)==find(y);\n  }\n  void unite(int x,int y){\n    x=ps[x];y=ps[y];\n\
    \    if(x==y) return;\n    if(rs[x]<rs[y]) swap(x,y);\n    rs[x]+=rs[y];\n   \
    \ for(int e:vs[y]){\n      ps[e]=x;\n      vs[x].emplace_back(e);\n    }\n   \
    \ vs[y].clear();\n    vs[y].shrink_to_fit();\n  }\n  const vector<int>& elements(int\
    \ x) const{return vs[x];}\n};\n//END CUT HERE\n#ifndef call_from_test\nsigned\
    \ main(){\n  return 0;\n}\n#endif\n"
  code: "#ifndef call_from_test\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #endif\n//BEGIN CUT HERE\nstruct QuickFind{\n  vector<int> rs,ps;\n  vector< vector<int>\
    \ > vs;\n  QuickFind(int n):rs(n,1),ps(n),vs(n){\n    iota(ps.begin(),ps.end(),0);\n\
    \    for(int i=0;i<n;i++) vs[i].assign(1,i);\n  }\n  int find(int x) const{return\
    \ ps[x];}\n  bool same(int x,int y) const{\n    return find(x)==find(y);\n  }\n\
    \  void unite(int x,int y){\n    x=ps[x];y=ps[y];\n    if(x==y) return;\n    if(rs[x]<rs[y])\
    \ swap(x,y);\n    rs[x]+=rs[y];\n    for(int e:vs[y]){\n      ps[e]=x;\n     \
    \ vs[x].emplace_back(e);\n    }\n    vs[y].clear();\n    vs[y].shrink_to_fit();\n\
    \  }\n  const vector<int>& elements(int x) const{return vs[x];}\n};\n//END CUT\
    \ HERE\n#ifndef call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/quickfind.cpp
  requiredBy: []
  timestamp: '2020-10-27 19:32:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A.quickfind.test.cpp
documentation_of: datastructure/quickfind.cpp
layout: document
redirect_from:
- /library/datastructure/quickfind.cpp
- /library/datastructure/quickfind.cpp.html
title: datastructure/quickfind.cpp
---