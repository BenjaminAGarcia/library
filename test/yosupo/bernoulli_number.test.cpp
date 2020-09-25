// verification-helper: PROBLEM https://judge.yosupo.jp/problem/bernoulli_number

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#include "../../combinatorics/bernoulli.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  Bernoulli<M> bs(conv);

  bs.build(n);
  for(int i=0;i<=n;i++){
    if(i) cout<<" ";
    cout<<bs[i];
  }
  cout<<endl;
  return 0;
}
