---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bflow/capacityscaling.cpp
    title: Minimum Cost Flow with Capacity Scaling
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/yosupo/assignment.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #line 1 \"bflow/capacityscaling.cpp\"\n\n#line 3 \"bflow/capacityscaling.cpp\"\
    \nusing namespace std;\n#endif\n//BEGIN CUT HERE\n// O(m^2 \\log m \\log U)\n\
    // U: maximum capacity\nenum Objective{\n  MINIMIZE = +1,\n  MAXIMIZE = -1,\n\
    };\ntemplate<typename Flow, typename Cost,\n         Objective objective = Objective::MINIMIZE>\n\
    struct MinCostFlow{\n  template<typename T> inline void chmin(T &x,T y){x=min(x,y);}\n\
    \n  struct Edge{\n    int src,dst;\n    Flow flow,cap;\n    Cost cost;\n    int\
    \ rev;\n    Edge(int src,int dst,Flow cap,Cost cost,int rev):\n      src(src),dst(dst),flow(0),cap(cap),cost(cost),rev(rev){}\n\
    \    Flow residual_cap()const{return cap-flow;}\n  };\n\n  struct EdgePtr{\n \
    \   int v,e;\n    EdgePtr(int v,int e):v(v),e(e){}\n  };\n\n  int n;\n  vector<vector<Edge>>\
    \ G;\n  vector<Flow> b;\n  vector<Cost> p;\n\n  MinCostFlow(int n):n(n),G(n),b(n,0){}\n\
    \n  EdgePtr add_edge(int src,int dst,Flow lower,Flow upper,Cost cost){\n    int\
    \ e=G[src].size();\n    int r=(src==dst?e+1:G[dst].size());\n    assert(lower<=upper);\n\
    \    G[src].emplace_back(src,dst,+upper,+cost*objective,r);\n    G[dst].emplace_back(dst,src,-lower,-cost*objective,e);\n\
    \    return EdgePtr(src,e);\n  }\n\n  const Edge &get_edge(EdgePtr ep)const{return\
    \ G[ep.v][ep.e];}\n\n  void push(Edge &e,Flow amount){\n    e.flow+=amount;\n\
    \    G[e.dst][e.rev].flow-=amount;\n  }\n\n  void add_supply(int v,Flow amount){b[v]+=amount;}\n\
    \  void add_demand(int v,Flow amount){b[v]-=amount;}\n\n  Cost residual_cost(const\
    \ Edge &e){\n    return e.cost+p[e.src]-p[e.dst];\n  }\n\n  vector<int> excess_vs,deficit_vs;\n\
    \  void saturate_negative(const Flow delta){\n    for(auto &es:G){\n      for(auto\
    \ &e:es){\n        Flow cap=e.residual_cap();\n        cap-=cap%delta;\n     \
    \   if(cap<0 or residual_cost(e)<0){\n          push(e,cap);\n          b[e.src]-=cap;\n\
    \          b[e.dst]+=cap;\n        }\n      }\n    }\n\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for(int v=0;v<n;v++){\n      if(b[v]>0) excess_vs.emplace_back(v);\n\
    \      if(b[v]<0) deficit_vs.emplace_back(v);\n    }\n  }\n\n  const Cost unreachable\
    \ = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  vector<Cost> dist;\n\
    \  vector<Edge*> parent;\n\n  struct P{\n    Cost first;\n    int second;\n  \
    \  P(Cost first,int second):first(first),second(second){}\n    bool operator<(const\
    \ P o)const{return first>o.first;}\n  };\n\n  priority_queue<P> pq;\n\n  template<typename\
    \ Predicate>\n  void eliminate(vector<int> &vs,Predicate predicate){\n    vs.erase(remove_if(begin(vs),end(vs),predicate),end(vs));\n\
    \  }\n\n  bool dual(const Flow delta){\n    eliminate(excess_vs, [&](int v){return\
    \ b[v]<+delta;});\n    eliminate(deficit_vs,[&](int v){return b[v]>-delta;});\n\
    \n    dist.assign(n,unreachable);\n    for(int v:excess_vs) pq.emplace(dist[v]=0,v);\n\
    \n    parent.assign(n,nullptr);\n    auto emplace=[&](Edge& e){\n      if(e.residual_cap()<delta)\
    \ return;\n      Cost nxt=dist[e.src]+residual_cost(e);\n      if(nxt>=dist[e.dst])\
    \ return;\n      pq.emplace(dist[e.dst]=nxt,e.dst);\n      parent[e.dst]=&e;\n\
    \    };\n\n    farthest=0;\n    int deficit_count=0;\n    while(!pq.empty()){\n\
    \      Cost d=pq.top().first;\n      int v=pq.top().second;\n      pq.pop();\n\
    \      if(dist[v]<d) continue;\n      farthest=d;\n\n      if(b[v]<=-delta) deficit_count++;\n\
    \      if(deficit_count>=(int)deficit_vs.size()) break;\n\n      for(auto &e:G[v])\
    \ emplace(e);\n    }\n    pq=decltype(pq)();\n\n    for(int v=0;v<n;v++)\n   \
    \   p[v]+=min(dist[v],farthest);\n\n    return deficit_count>0;\n  }\n\n  void\
    \ primal(const Flow delta){\n    for(int t:deficit_vs){\n      if(dist[t]>farthest)\
    \ continue;\n      Flow f=-b[t];\n      int v;\n      for(v=t;parent[v];v=parent[v]->src)\n\
    \        chmin(f,parent[v]->residual_cap());\n      chmin(f,b[v]);\n\n      f-=f%delta;\n\
    \      if(f<=0) continue;\n\n      for(v=t;parent[v];){\n        auto &e=*parent[v];\n\
    \        push(e,f);\n        int u=parent[v]->src;\n        if(e.residual_cap()<=0)\
    \ parent[v]=nullptr;\n        v=u;\n      }\n      b[t]+=f;\n      b[v]-=f;\n\
    \    }\n  }\n\n  template<Flow SCALING_FACTOR=2>\n  bool build(){\n    p.resize(n);\n\
    \    Flow max_flow=1;\n    for(auto t:b) max_flow=max({max_flow,t,-t});\n    for(auto\
    \ &es:G)\n      for(auto &e:es)\n        max_flow=max({max_flow,e.residual_cap(),-e.residual_cap()});\n\
    \n    Flow delta=1;\n    while(delta<max_flow) delta*=SCALING_FACTOR;\n    for(;delta;delta/=SCALING_FACTOR){\n\
    \      saturate_negative(delta);\n      while(dual(delta)) primal(delta);\n  \
    \  }\n\n    return excess_vs.empty() and deficit_vs.empty();\n  }\n\n  template<typename\
    \ T=Cost>\n  T get_cost(){\n    T res=0;\n    for(auto &es:G)\n      for(auto\
    \ &e:es)\n        res+=T(e.flow)*T(e.cost)/T(objective);\n    return res/T(2);\n\
    \  }\n  template<typename T=Cost> T get_gain(){return get_cost();}\n\n  vector<Cost>\
    \ get_potential(){\n    fill(p.begin(),p.end(),0);\n    for(int i=0;i<n;i++)\n\
    \      for(auto &es:G)\n        for(auto &e:es)\n          if(e.residual_cap()>0)\n\
    \            chmin(p[e.dst],p[e.src]+e.cost);\n    return p;\n  }\n};\n\ntemplate<typename\
    \ Flow, typename Cost>\nusing MaxGainFlow = MinCostFlow<Flow, Cost, Objective::MAXIMIZE>;\n\
    //END CUT HERE\n#ifndef call_from_test\n//INSERT ABOVE HERE\nsigned main(){\n\
    \  return 0;\n}\n#endif\n#line 8 \"test/yosupo/assignment.test.cpp\"\n#undef call_from_test\n\
    \n#ifdef SANITIZE\n#define IGNORE\n#endif\n\nsigned main(){\n  cin.tie(0);\n \
    \ ios::sync_with_stdio(0);\n  using ll = long long;\n\n  int n;\n  cin>>n;\n \
    \ MinCostFlow<ll, ll> G(n+n);\n\n  for(int i=0;i<n;i++){\n    G.add_supply(0+i,1);\n\
    \    G.add_demand(n+i,1);\n  }\n\n  vector<vector<decltype(G)::EdgePtr>> E(n);\n\
    \  for(int i=0;i<n;i++){\n    for(int j=0;j<n;j++){\n      int a;\n      cin>>a;\n\
    \      E[i].emplace_back(G.add_edge(i,n+j,0,1,a));\n    }\n  }\n\n  assert(G.build());\n\
    \  cout<<G.get_cost()<<endl;\n  for(int i=0;i<n;i++){\n    if(i) cout<<' ';\n\
    \    for(auto e:E[i])\n      if(G.get_edge(e).flow)\n        cout<<G.get_edge(e).dst-n;\n\
    \  }\n  cout<<endl;\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n#include \"\
    ../../bflow/capacityscaling.cpp\"\n#undef call_from_test\n\n#ifdef SANITIZE\n\
    #define IGNORE\n#endif\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \  using ll = long long;\n\n  int n;\n  cin>>n;\n  MinCostFlow<ll, ll> G(n+n);\n\
    \n  for(int i=0;i<n;i++){\n    G.add_supply(0+i,1);\n    G.add_demand(n+i,1);\n\
    \  }\n\n  vector<vector<decltype(G)::EdgePtr>> E(n);\n  for(int i=0;i<n;i++){\n\
    \    for(int j=0;j<n;j++){\n      int a;\n      cin>>a;\n      E[i].emplace_back(G.add_edge(i,n+j,0,1,a));\n\
    \    }\n  }\n\n  assert(G.build());\n  cout<<G.get_cost()<<endl;\n  for(int i=0;i<n;i++){\n\
    \    if(i) cout<<' ';\n    for(auto e:E[i])\n      if(G.get_edge(e).flow)\n  \
    \      cout<<G.get_edge(e).dst-n;\n  }\n  cout<<endl;\n  return 0;\n}\n"
  dependsOn:
  - bflow/capacityscaling.cpp
  isVerificationFile: true
  path: test/yosupo/assignment.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 16:41:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.test.cpp
- /verify/test/yosupo/assignment.test.cpp.html
title: test/yosupo/assignment.test.cpp
---