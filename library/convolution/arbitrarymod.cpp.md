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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: convolution/arbitrarymod.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/arbitrarymod.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-12 17:02:32+09:00




## Depends on

* :heavy_check_mark: <a href="fastfouriertransform.cpp.html">convolution/fastfouriertransform.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.test.cpp.html">test/yosupo/convolution_mod_1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/0444.test.cpp.html">test/yukicoder/0444.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2744.test.cpp.html">test/yukicoder/2744.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "fastfouriertransform.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
struct ArbitraryMod{
  using dbl=FFT::dbl;
  using num=FFT::num;

  vector<T> multiply(vector<T> as,vector<T> bs){
    int need=as.size()+bs.size()-1;
    int sz=1;
    while(sz<need) sz<<=1;
    vector<num> fa(sz),fb(sz);
    for(int i=0;i<(int)as.size();i++)
      fa[i]=num(as[i].v&((1<<15)-1),as[i].v>>15);
    for(int i=0;i<(int)bs.size();i++)
      fb[i]=num(bs[i].v&((1<<15)-1),bs[i].v>>15);

    fft(fa);fft(fb);

    dbl ratio=0.25/sz;
    num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
    for(int i=0;i<=(sz>>1);i++){
      int j=(sz-i)&(sz-1);
      num a1=(fa[i]+conj(fa[j]));
      num a2=(fa[i]-conj(fa[j]))*r2;
      num b1=(fb[i]+conj(fb[j]))*r3;
      num b2=(fb[i]-conj(fb[j]))*r4;
      if(i!=j){
        num c1=(fa[j]+conj(fa[i]));
        num c2=(fa[j]-conj(fa[i]))*r2;
        num d1=(fb[j]+conj(fb[i]))*r3;
        num d2=(fb[j]-conj(fb[i]))*r4;
        fa[i]=c1*d1+c2*d2*r5;
        fb[i]=c1*d2+c2*d1;
      }
      fa[j]=a1*b1+a2*b2*r5;
      fb[j]=a1*b2+a2*b1;
    }
    fft(fa);fft(fb);

    vector<T> cs(need);
    using ll = long long;
    for(int i=0;i<need;i++){
      ll aa=T(llround(fa[i].x)).v;
      ll bb=T(llround(fb[i].x)).v;
      ll cc=T(llround(fa[i].y)).v;
      cs[i]=T(aa+(bb<<15)+(cc<<30));
    }
    return cs;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 398, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/arbitrarymod.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

