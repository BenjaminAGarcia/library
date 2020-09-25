// verification-helper: PROBLEM https://judge.yosupo.jp/problem/dominatortree

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/dominatortree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,m,s;
  cin>>n>>m>>s;
  DominatorTree G(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    G.add_edge(a,b);
  }
  G.build(s);
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<G[i];
  }
  cout<<endl;
  return 0;
}
