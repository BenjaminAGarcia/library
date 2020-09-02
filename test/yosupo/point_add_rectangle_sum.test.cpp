#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../vector/compress.cpp"
#include "../../segtree/count/dynamic_offline.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> xs(n+q),ys(n+q),ws(n+q);
  for(int i=0;i<n;i++)
    cin>>xs[i]>>ys[i]>>ws[i];

  vector<int> ts(q);
  vector<int> ls(q),ds(q),rs(q),us(q);
  for(int i=0;i<q;i++){
    cin>>ts[i];
    if(ts[i]==0) cin>>xs[n+i]>>ys[n+i]>>ws[n+i];
    if(ts[i]==1) cin>>ls[i]>>ds[i]>>rs[i]>>us[i];
  }

  auto vs=compress(xs);
  auto idx=
    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};

  using ll = long long;
  RangeCount<int, ll> seg(vs.size());

  for(int i=0;i<n;i++)
    seg.preupdate(idx(xs[i]),ys[i]);

  for(int i=0;i<q;i++)
    if(ts[i]==0) seg.preupdate(idx(xs[n+i]),ys[n+i]);

  seg.build();

  for(int i=0;i<n;i++)
    seg.update(idx(xs[i]),ys[i],ws[i]);

  for(int i=0;i<q;i++){
    if(ts[i]==0) seg.update(idx(xs[n+i]),ys[n+i],ws[n+i]);
    if(ts[i]==1) cout<<seg.query(idx(ls[i]),idx(rs[i]),ds[i],us[i])<<"\n";
  }
  cout<<flush;
  return 0;
}
