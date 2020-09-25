// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/kdtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  KDTree<int> kd;
  for(int i=0;i<n;i++) {
    int x,y;
    cin>>x>>y;
    kd.add_point(i,x,y);
  }
  int root=kd.build();

  int q;
  cin>>q;
  int sx,tx,sy,ty;
  vector<decltype(kd)::Point> ans;
  for(int i=0;i<q;i++){
    cin>>sx>>tx>>sy>>ty;
    ans.clear();
    kd.find(root,sx,tx,sy,ty,0,ans);
    sort(ans.begin(),ans.end());
    for(auto p:ans) cout<<p.id<<"\n";
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}
