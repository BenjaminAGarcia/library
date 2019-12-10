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


# :heavy_check_mark: test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp
<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp">View this file on GitHub</a> (Last commit date: 2019-12-09 23:51:01 +0900)


* see: <a href="https://judge.yosupo.jp/problem/vertex_add_subtree_sum">https://judge.yosupo.jp/problem/vertex_add_subtree_sum</a>


## Dependencies
* :heavy_check_mark: <a href="../../../library/linkcuttree/base.cpp.html">linkcuttree/base.cpp</a>
* :heavy_check_mark: <a href="../../../library/linkcuttree/subtree.cpp.html">linkcuttree/subtree.cpp</a>
* :heavy_check_mark: <a href="../../../library/tools/fastio.cpp.html">tools/fastio.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/subtree.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,q;
  cin>>n>>q;
  vector<ll> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  using Node = NodeBase<ll>;
  constexpr size_t LIM = 1e6;
  using LCT = SubTree<Node, LIM>;
  LCT lct;

  vector<LCT::Node*> vs(n);
  for(int i=0;i<n;i++)
    vs[i]=lct.create(i,as[i]);

  for(int i=1;i<n;i++){
    int p;
    cin>>p;
    lct.link(vs[p],vs[i]);
  }

  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==0){
      int u,x;
      cin>>u>>x;
      as[u]+=x;
      lct.set_val(vs[u],as[u]);
    }
    if(t==1){
      int u;
      cin>>u;
      Node* p=lct.parent(vs[u]);
      if(p) lct.cut(vs[u]);
      cout<<lct.query(vs[u])<<"\n";
      if(p) lct.link(p,vs[u]);
    }
  }
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
