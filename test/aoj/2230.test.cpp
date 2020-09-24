#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2230"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../mincostflow/primaldual.cpp"
#include "../../mincostflow/negativeedge.cpp"
#undef call_from_test

signed main(){
  using P = pair<int, int>;
  using ll = long long;
  const ll INF = 1e9;

  int n,m;
  cin>>n>>m;
  vector< vector<P> > H(n);
  NegativeEdge<ll, ll> G(n);
  for(int i=0;i<m;i++){
    int x,y,s;
    cin>>x>>y>>s;
    H[x].emplace_back(y,s);
    G.add_edge(y,x,1,-s-INF);
    G.add_edge(y,x,INF,-s);
  }

  vector<int> dp(n,0);
  for(int i=0;i<n;i++)
    for(auto e:H[i])
      chmax(dp[e.first],dp[i]+e.second);
  G.add_edge(0,n-1,INF,dp[n-1]);

  int ok=0;
  cout<<INF*m+G.flow(ok)<<endl;
  assert(ok);
  return 0;
}
