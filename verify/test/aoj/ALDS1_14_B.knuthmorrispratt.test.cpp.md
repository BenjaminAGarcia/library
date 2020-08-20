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


# :heavy_check_mark: test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-20 15:14:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/string/knuthmorrispratt.cpp.html">string/knuthmorrispratt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/knuthmorrispratt.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string t,p;
  cin>>t>>p;

  vector<int> res=pattern_match(p,t);
  for(int x:res) cout<<x<<"\n";
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 2 "string/knuthmorrispratt.cpp"

#ifndef call_from_test
#line 5 "string/knuthmorrispratt.cpp"
using namespace std;
#endif
/*
 * @see https://snuke.hatenablog.com/entry/2017/07/18/101026
 */
//BEGIN CUT HERE
// longest prefix suffix matching of [0, i)
vector<int> knuth_morris_pratt(const string &s){
  int n=s.size();
  vector<int> kmp(n+1,-1);
  for(int i=0,j=-1;i<n;i++){
    while(~j&&s[i]!=s[j]) j=kmp[j];
    kmp[i+1]=++j;
    if(i+1<n&&s[i+1]==s[j]) kmp[i+1]=kmp[j];
  }
  return kmp;
}
// positions for t that match s
vector<int> pattern_match(string s,string t){
  int n=s.size(),m=t.size();
  vector<int> kmp=knuth_morris_pratt(s);

  vector<int> res;
  int i=0,j=0;
  while(i+j<m){
    if(s[j]==t[i+j]){
      if(++j!=n) continue;
      res.emplace_back(i);
    }
    i+=j-kmp[j];
    j=max(kmp[j],0);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE

// test knuth_morris_pratt
signed ABC135_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s,t;
  cin>>s>>t;

  int n=s.size(),m=t.size();

  string b;
  while(b.size()<t.size()) b+=s;
  auto kmp=knuth_morris_pratt(t+'$'+b+b);

  vector<int> match(n);
  for(int i=m+1;i<=m+n;i++)
    match[i-(m+1)]=kmp[i+m]==m;

  vector< vector<int> > G(n);
  for(int i=0;i<n;i++)
    if(match[i]) G[i].emplace_back((i+m)%n);

  vector<int> indeg(n,0);
  for(int i=0;i<n;i++)
    for(int j:G[i]) indeg[j]++;

  queue<int> que;
  for(int i=0;i<n;i++)
    if(indeg[i]==0) que.emplace(i);

  vector<int> dp(n,0);
  while(!que.empty()){
    int v=que.front();que.pop();
    for(int u:G[v]){
      chmax(dp[u],dp[v]+1);
      indeg[u]--;
      if(indeg[u]==0) que.emplace(u);
    }
  }

  for(int i=0;i<n;i++){
    if(indeg[i]!=0){
      cout<<-1<<endl;
      return 0;
    }
  }

  cout<<*max_element(dp.begin(),dp.end())<<endl;
  return 0;
}
/*
  verified on 2020/08/20
  https://atcoder.jp/contests/abc135/tasks/abc135_f
*/

signed main(){
  ABC135_F();
  return 0;
}
#endif
#line 8 "test/aoj/ALDS1_14_B.knuthmorrispratt.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string t,p;
  cin>>t>>p;

  vector<int> res=pattern_match(p,t);
  for(int x:res) cout<<x<<"\n";
  cout<<flush;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

