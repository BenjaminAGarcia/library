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


# :heavy_check_mark: polynomial/interpolate.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#89693d3333328e76f4fdeed379e8f9ea">polynomial</a>
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/interpolate.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-16 18:51:14+09:00




## Depends on

* :heavy_check_mark: <a href="formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :heavy_check_mark: <a href="multieval.cpp.html">polynomial/multieval.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "formalpowerseries.cpp"
#include "multieval.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
// O(N log^2 N)
template<typename T>
struct Interpolate : MultiEval<T>{
  using super=MultiEval<T>;
  using super::super;

  using typename super::Poly;
  using super::FPS;
  using super::mem;

  Poly interpolate(const vector<T> &xs,const vector<T> &ws,int l,int r){
    if(l+1==r) return Poly({ws[l]});
    int m=(l+r)>>1;
    return FPS.add(FPS.mul(interpolate(xs,ws,l,m),mem[{m,r}]),
                   FPS.mul(interpolate(xs,ws,m,r),mem[{l,m}]));
  }

  vector<T> build(const vector<T> &xs,const vector<T> &ys){
    int n=xs.size();
    mem.clear();
    super::dfs(xs,0,n);
    auto ls=FPS.diff(mem[{0,n}]);
    ls.resize(n,T(0));
    vector<T> ws(n);
    super::multi_eval(ls,ws,0,n);
    for(int i=0;i<n;i++) ws[i]=ys[i]/ws[i];
    return interpolate(xs,ws,0,n);
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 309, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/interpolate.cpp: line 8: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

