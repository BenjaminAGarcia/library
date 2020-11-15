#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
auto divide_by_two(T x)
  ->enable_if_t<!is_class<T>::value, T>{
  return x/T(2);
}

template<typename T>
auto divide_by_two(T x)
  ->enable_if_t< is_class<T>::value, T>{
  static const T inv = T(2).inv();
  return x*inv;
}
auto zeta=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=x;
  hi=y;
};
auto moebius=[](auto& lo,auto& hi){
  auto x=lo+hi,y=lo-hi;
  lo=divide_by_two(x);
  hi=divide_by_two(y);
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "fwht.cpp"
#include "../../mod/mint.cpp"
#undef call_from_test

signed CGR002_H(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;
  const int MOD = 998244353;
  using M = Mint<int, MOD>;

  int n,k;
  cin>>n>>k;

  ll p,q,r;
  cin>>p>>q>>r;

  int ofs=0;
  vector<int> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
    ofs^=a[i];
    b[i]^=a[i];
    c[i]^=a[i];
    a[i]=0;
  }

  vector<vector<ll> > vm((1<<k),vector<ll>(4,0));
  for(int t=0;t<4;t++){
    vector<ll> vs(1<<k,0);
    for(int i=0;i<n;i++){
      vs[a[i]]+=(t==0);
      vs[b[i]]+=(t==1);
      vs[c[i]]+=(t==2);
      vs[b[i]^c[i]]+=(t==3);
    }
    fwht(vs,zeta);
    for(int i=0;i<(1<<k);i++) vm[i][t]=vs[i];
  }

  vector<M> vs(1<<k,1);
  for(int i=0;i<(1<<k);i++){
    ll x=(vm[i][0]+vm[i][1]+vm[i][2]+vm[i][3])/4;
    ll y=(vm[i][0]+vm[i][1]-vm[i][2]-vm[i][3])/4;
    ll z=(vm[i][0]-vm[i][1]+vm[i][2]-vm[i][3])/4;
    ll w=(vm[i][0]-vm[i][1]-vm[i][2]+vm[i][3])/4;

    vs[i]*=M(p+q+r).pow(x);
    vs[i]*=M(p+q-r).pow(y);
    vs[i]*=M(p-q+r).pow(z);
    vs[i]*=M(p-q-r).pow(w);
  }

  fwht(vs,moebius);
  for(int i=0;i<(1<<k);i++){
    if(i) cout<<" ";
    cout<<vs[ofs^i].v;
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2020/11/15
  https://codeforces.com/contest/1119/problem/H
*/

//INSERT ABOVE HERE
signed main(){
  // CGR002_H();
  return 0;
}
#endif
