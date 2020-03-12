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


# :heavy_check_mark: test/yosupo/sqrt_of_formal_power_series.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/sqrt_of_formal_power_series.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-12 17:15:27+09:00


* see: <a href="https://judge.yosupo.jp/problem/sqrt_of_formal_power_series">https://judge.yosupo.jp/problem/sqrt_of_formal_power_series</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/combinatorics/enumeration.cpp.html">combinatorics/enumeration.cpp</a>
* :heavy_check_mark: <a href="../../../library/convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="../../../library/mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="../../../library/mod/sqrt.cpp.html">mod/sqrt.cpp</a>
* :heavy_check_mark: <a href="../../../library/polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/drop.cpp.html">tools/drop.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/drop.cpp"
#include "../../mod/sqrt.cpp"
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../combinatorics/enumeration.cpp"
#include "../../polynomial/formalpowerseries.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  NTT<2> ntt;
  using M = NTT<2>::M;
  auto conv=[&](auto as,auto bs){return ntt.multiply(as,bs);};
  FormalPowerSeries<M> FPS(conv);

  deque<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  while(!as.empty()&&as.front()==0) as.pop_front();

  if(as.empty()){
    for(int i=0;i<n;i++){
      if(i) cout<<" ";
      cout<<0;
    }
    cout<<endl;
    return 0;
  }

  int m=as.size();
  if((n-m)&1) drop(-1);

  auto ss=mod_sqrt(as[0],ntt.md);
  if(ss.empty()) drop(-1);

  vector<M> ps(n,M(0));
  for(int i=0;i<m;i++) ps[i]=M(as[i])/M(as[0]);

  auto bs=FPS.sqrt(ps,n);
  bs.insert(bs.begin(),(n-m)/2,M(0));
  for(int i=0;i<n;i++){
    if(i) cout<<" ";
    cout<<bs[i]*ss[0];
  }
  cout<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 281, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: convolution/numbertheoretictransform.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
