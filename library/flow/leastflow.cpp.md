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


# :heavy_check_mark: flow/leastflow.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/leastflow.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-27 09:03:53+09:00




## Depends on

* :heavy_check_mark: <a href="dinic.cpp.html">flow/dinic.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/1615.test.cpp.html">test/aoj/1615.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "dinic.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
struct LeastFlow{
  Dinic<T, true> G;
  int X,Y;
  T sum;
  LeastFlow(int n):G(n+2),X(n),Y(n+1),sum(0){}

  void add_edge(int from,int to,T low,T hgh){
    assert(low<=hgh);
    G.add_edge(from,to,hgh-low);
    G.add_edge(X,to,low);
    G.add_edge(from,Y,low);
    sum+=low;
  }

  T flow(int s,int t){
    T a=G.flow(X,Y);
    T b=G.flow(s,Y);
    T c=G.flow(X,t);
    T d=G.flow(s,t);
    return (b==c&&a+b==sum)?b+d:T(-1);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/leastflow.cpp: line 6: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

