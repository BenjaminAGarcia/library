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


# :heavy_check_mark: test/yosupo/point_add_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_add_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-05 21:59:12+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/binaryindexedtree.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  BIT<long long> bit(n);
  for(int i=0;i<n;i++) bit.add0(i,as[i]);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int p,x;
      cin>>p>>x;
      bit.add0(p,x);
    }
    if(t==1){
      int l,r;
      cin>>l>>r;
      cout<<bit.query0(l,r)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_add_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "datastructure/binaryindexedtree.cpp"

#line 3 "datastructure/binaryindexedtree.cpp"
using namespace std;
#endif
/*
 * @docs docs/binaryindexedtree.md
 */
//BEGIN CUT HERE
template<typename T>
struct BIT{
  int n;
  vector<T> bit;
  // 1-indexed
  BIT(int n_):n(n_+1),bit(n+1,0){}

  T sum(int i){
    T s(0);
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }

  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }

  // [l, r)
  T query(int l,int r){
    return sum(r-1)-sum(l-1);
  }

  int lower_bound(int w){
    if(w<=0) return 0;
    int x=0,r=1;
    while(r<n) r<<=1;
    for(int k=r;k>0;k>>=1){
      if(x+k<=n&&bit[x+k]<w){
        w-=bit[x+k];
        x+=k;
      }
    }
    return x+1;
  }

  // 0-indexed
  T sum0(int i){return sum(i+1);}
  void add0(int i,T a){add(i+1,a);}
  T query0(int l,int r){return sum(r)-sum(l);}
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 8 "test/yosupo/point_add_range_sum.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  BIT<long long> bit(n);
  for(int i=0;i<n;i++) bit.add0(i,as[i]);

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int p,x;
      cin>>p>>x;
      bit.add0(p,x);
    }
    if(t==1){
      int l,r;
      cin>>l>>r;
      cout<<bit.query0(l,r)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

