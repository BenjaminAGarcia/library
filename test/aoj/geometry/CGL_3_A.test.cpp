// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A
#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../../geometry/geometry.cpp"
#undef call_from_test

//Area of Polygon
signed main(){
  int n;
  cin>>n;
  Polygon ps(n);
  cin>>ps;
  cout<<fixed<<setprecision(1)<<area(ps)<<endl;
  return 0;
}
