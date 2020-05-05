---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/yosupo/shortest_path.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/shortest_path.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-05 14:35:59+09:00


* see: <a href="https://judge.yosupo.jp/problem/shortest_path">https://judge.yosupo.jp/problem/shortest_path</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/dijkstra.cpp.html">graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/drop.cpp.html">tools/drop.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../graph/dijkstra.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,m,s,t;
  cin>>n>>m>>s>>t;

  using ll = long long;
  Dijkstra<ll> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  G.build(s);
  auto ps=G.restore(t);
  if(ps.empty()) drop(-1);

  int y=ps.size()-1;
  cout<<G[t]<<' '<<y<<newl;
  for(int i=0;i<y;i++) cout<<ps[i]<<' '<<ps[i+1]<<newl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/shortest_path.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "tools/drop.cpp"

#line 3 "tools/drop.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
#line 1 "graph/dijkstra.cpp"

#line 3 "graph/dijkstra.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct Dijkstra{
  struct Edge{
    int to;
    T cost;
    Edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const Edge &o)const{return cost>o.cost;}
  };

  vector< vector<Edge> > G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n):G(n){}

  void add_edge(int u,int v,T c){
    G[u].emplace_back(v,c);
  }

  void build(int s){
    int n=G.size();
    ds.assign(n,numeric_limits<T>::max());
    bs.assign(n,-1);

    priority_queue<Edge> pq;
    ds[s]=0;
    pq.emplace(s,ds[s]);

    while(!pq.empty()){
      auto p=pq.top();pq.pop();
      int v=p.to;
      if(ds[v]<p.cost) continue;
      for(auto e:G[v]){
        if(ds[e.to]>ds[v]+e.cost){
          ds[e.to]=ds[v]+e.cost;
          bs[e.to]=v;
          pq.emplace(e.to,ds[e.to]);
        }
      }
    }
  }

  T operator[](int k){return ds[k];}

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]<0) return res;
    while(~to) res.emplace_back(to),to=bs[to];
    reverse(res.begin(),res.end());
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 9 "test/yosupo/shortest_path.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const char newl = '\n';

  int n,m,s,t;
  cin>>n>>m>>s>>t;

  using ll = long long;
  Dijkstra<ll> G(n);
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G.add_edge(a,b,c);
  }

  G.build(s);
  auto ps=G.restore(t);
  if(ps.empty()) drop(-1);

  int y=ps.size()-1;
  cout<<G[t]<<' '<<y<<newl;
  for(int i=0;i<y;i++) cout<<ps[i]<<' '<<ps[i+1]<<newl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
