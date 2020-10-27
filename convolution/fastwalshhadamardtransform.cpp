#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T>
void FWT(vector<T> &as){
  int n=as.size();
  for(int d=1;d<n;d<<=1){
    for(int m=d<<1,i=0;i<n;i+=m){
      for(int j=0;j<d;j++){
        T x=as[i+j],y=as[i+j+d];
        as[i+j+0]=x+y;
        as[i+j+d]=x-y;
      }
    }
  }
}

template<typename T>
void multiply(vector<T> &as,const vector<T> &bs){
  for(int i=0;i<(int)as.size();i++)
    as[i]=as[i]*bs[i];
}

template<typename T>
void UFWT(vector<T> &as){
  T inv2=T(2).inv();
  int n=as.size();
  for(int d=1;d<n;d<<=1){
    for(int m=d<<1,i=0;i<n;i+=m){
      for(int j=0;j<d;j++){
        T x=as[i+j],y=as[i+j+d];
        as[i+j+0]=(x+y)*inv2;
        as[i+j+d]=(x-y)*inv2;
      }
    }
  }
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

//INSERT ABOVE HERE
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
    FWT(vs);
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

  UFWT(vs);
  for(int i=0;i<(1<<k);i++){
    if(i) cout<<" ";
    cout<<vs[ofs^i].v;
  }
  cout<<endl;
  return 0;
}
/*
  verified on 2020/05/07
  https://codeforces.com/contest/1119/problem/H
*/

signed main(){
  CGR002_H();
  return 0;
}
#endif
