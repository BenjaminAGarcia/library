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


# :heavy_check_mark: test/yosupo/rectangle_sum.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/rectangle_sum.test.cpp">View this file on GitHub</a> (Last commit date: 2019-12-09 23:51:01 +0900)


* see: <a href="https://judge.yosupo.jp/problem/rectangle_sum">https://judge.yosupo.jp/problem/rectangle_sum</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/segtree/count/dynamic_offline.cpp.html">segtree/count/dynamic_offline.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/compress.cpp.html">tools/compress.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/compress.cpp"
#include "../../segtree/count/dynamic_offline.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  vector<int> xs(n),ys(n),ws(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i]>>ws[i];

  auto vs=compress(xs);
  auto idx=
    [&](int x){return lower_bound(vs.begin(),vs.end(),x)-vs.begin();};

  using ll = long long;
  RangeCount<ll> seg(vs.size());

  for(int i=0;i<n;i++)
    seg.preupdate(idx(xs[i]),ys[i]);

  seg.build();

  for(int i=0;i<n;i++)
    seg.update(idx(xs[i]),ys[i],ws[i]);

  for(int i=0;i<q;i++){
    int l,d,r,u;
    cin>>l>>d>>r>>u;
    cout<<seg.query(idx(l),idx(r),d,u)<<"\n";
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
