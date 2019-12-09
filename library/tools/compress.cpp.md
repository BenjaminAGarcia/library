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


# :heavy_check_mark: tools/compress.cpp
* category: tools


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [linearalgebra/squarematrix.cpp](../linearalgebra/squarematrix.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/0613.test.cpp](../../verify/test/aoj/0613.test.cpp.html)
* :heavy_check_mark: [test/aoj/1599.test.cpp](../../verify/test/aoj/1599.test.cpp.html)
* :heavy_check_mark: [test/aoj/2359.test.cpp](../../verify/test/aoj/2359.test.cpp.html)
* :heavy_check_mark: [test/yosupo/rectangle_sum.test.cpp](../../verify/test/yosupo/rectangle_sum.test.cpp.html)


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
template<typename V>
V compress(V v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}
map<char, int> dict(const string &v){
  return dict(vector<char>(v.begin(),v.end()));
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed ABC036_C(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  auto v=compress(a);
  auto m=dict(v);
  for(int i=0;i<n;i++) cout<<m[a[i]]<<endl;
  return 0;
}
/*
  verified on 2018/08/26
  https://abc036.contest.atcoder.jp/tasks/abc036_c
*/

signed main(){
  ABC036_C();
  return 0;
}
#endif

```
{% endraw %}

[Back to top page](../../index.html)
