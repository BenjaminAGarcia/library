#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../datastructure/skewheap.cpp"
#undef call_from_test

#endif
//BEGIN CUT HERE
template<typename T>
T optimalbinarytree(vector<T> ws){
  const T INF = numeric_limits<T>::max()/2;
  using Heap=SkewHeap<T, T>;

  auto g=[](T a,T b){return a+b;};
  auto c=[](T a,T b){return a>b;};
  Heap heap(g,g,c,INF,0);

  int n=ws.size();
  vector<typename Heap::Node* > hs(n-1,nullptr);
  vector<int> ls(n),rs(n);
  vector<T> cs(n-1);

  using P = pair<T, int>;
  priority_queue<P,vector<P>,greater<P> > pq;
  for(int i=0;i<n-1;i++){
    ls[i]=i-1;
    rs[i]=i+1;
    cs[i]=ws[i]+ws[i+1];
    pq.emplace(cs[i],i);
  }

  T res=0;
  for(int k=0;k<n-1;k++){
    T c;
    int i;
    do{
      tie(c,i)=pq.top();pq.pop();
    }while(rs[i]<0||cs[i]!=c);

    bool ml=false,mr=false;
    if(ws[i]+heap.top(hs[i])==c){
      hs[i]=heap.pop(hs[i]);
      ml=true;
    }else if(ws[i]+ws[rs[i]]==c){
      ml=mr=true;
    }else if(heap.top(hs[i])+heap.snd(hs[i])==c){
      hs[i]=heap.pop(heap.pop(hs[i]));
    }else{
      hs[i]=heap.pop(hs[i]);
      mr=true;
    }

    res+=c;
    hs[i]=heap.meld(hs[i],heap.push(c));

    if(ml) ws[i]=INF;
    if(mr) ws[rs[i]]=INF;

    if(ml&&i>0){
      int j=ls[i];
      hs[j]=heap.meld(hs[j],hs[i]);
      rs[j]=rs[i];
      rs[i]=-1;
      ls[rs[j]]=j;
      i=j;
    }

    if(mr&&rs[i]+1<n){
      int j=rs[i];
      hs[i]=heap.meld(hs[i],hs[j]);
      rs[i]=rs[j];
      rs[j]=-1;
      ls[rs[i]]=i;
    }

    cs[i]=min({ws[i]+ws[rs[i]],INF,
               min(ws[i],ws[rs[i]])+heap.top(hs[i]),
               heap.top(hs[i])+heap.snd(hs[i])});
    pq.emplace(cs[i],i);
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
