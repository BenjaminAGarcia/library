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


# :question: vector/compress.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#6ba8844da718b4a65f60dbfd0d92d6ef">vector</a>
* <a href="{{ site.github.repository_url }}/blob/master/vector/compress.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-18 17:56:15+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0343.test.cpp.html">test/aoj/0343.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0613.test.cpp.html">test/aoj/0613.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1300.test.cpp.html">test/aoj/1300.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1599.test.cpp.html">test/aoj/1599.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1607.test.cpp.html">test/aoj/1607.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2359.test.cpp.html">test/aoj/2359.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2563.test.cpp.html">test/aoj/2563.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/line_add_get_min.test.cpp.html">test/yosupo/line_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_rectangle_sum.test.cpp.html">test/yosupo/point_add_rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/rectangle_sum.test.cpp.html">test/yosupo/rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1732.test.cpp.html">test/yukicoder/1732.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/4778.test.cpp.html">test/yukicoder/4778.test.cpp</a>
* :x: <a href="../../verify/test/yukicoder/4852.test.cpp.html">test/yukicoder/4852.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, int> dict(const vector<T> &vs){
  map<T, int> res;
  for(int i=0;i<(int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "vector/compress.cpp"

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, int> dict(const vector<T> &vs){
  map<T, int> res;
  for(int i=0;i<(int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

