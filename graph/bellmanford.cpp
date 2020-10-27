#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
struct BellmanFord{
  struct edge{
    int u,v;
    T w;
    edge(int u,int v,T w):u(u),v(v),w(w){}
  };

  vector< vector<int> > G;
  vector<int> used,reach;
  BellmanFord(int n):G(n),used(n,0),reach(n,1){}

  vector<edge> es;
  void add_edge(int u,int v,T c){
    es.emplace_back(u,v,c);
    G[u].emplace_back(v);
  }

  vector<T> build(int from,int &neg_loop){
    const T INF = numeric_limits<T>::max();
    int n=G.size();
    vector<T> ds(n,INF);
    ds[from]=0;
    for(int j=0;j<n;j++){
      bool update=0;
      for(auto e:es){
        if(!reach[e.u] or !reach[e.v] or ds[e.u]==INF) continue;
        if(ds[e.v]>ds[e.u]+e.w){
          ds[e.v]=ds[e.u]+e.w;
          update=1;
        }
      }
      if(!update) break;
      if(j==n-1){
        neg_loop=1;
        return ds;
      }
    }
    neg_loop=0;
    return ds;
  }

  void dfs(int v){
    if(used[v]) return;
    used[v]=1;
    for(int u:G[v]) dfs(u);
  }

  T shortest_path(int from,int to,int &neg_loop){
    int n=G.size();
    for(int i=0;i<n;i++){
      fill(used.begin(),used.end(),0);
      dfs(i);
      reach[i]=used[to];
    }
    return build(from,neg_loop)[to];
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
