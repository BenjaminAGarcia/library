#include<iostream>
#include<string>
using namespace std;
int main(){
  int i,j,k;
  string que;
  cin >> que;
  while(que[0]!='#'){
    
    int v1=0,v2=0;
    int bv1,bv2;
    int br1,br2;
    int bl1,bl2;
    int r1=0,l1=0,r2=0,l2=0;
    int b;
    for(i=0;i<que.size();i++){
      b=que[i]-'0';
      bv1=v1;bv2=v2;
      if(i%2==0) {
	br1=r1;bl2=l2;
	r1=b;l2=b;
	if(r1==1||r1==4||r1==7){
	  if(l1==2||l1==3||l1==6||l1==8||l1==9) {
	    v1++;
	    r1=br1;
	    l1=b;
	  }
	}else if(r1==2||r1==8){
	  if(l1==3||l1==6||l1==9) {
	    v1++;
	    r1=br1;
	    l1=b;
	  }
	}
	if(l2==3||l2==6||l2==9){
	  if(r2==1||r2==2||r2==4||r2==7||r2==8) {
	    v2++;
	    l2=bl2;
	    r2=b;
	  }
	}else if(l2==2||l2==8){
	  if(r2==1||r2==4||r2==7) {
	    v2++;
	    l2=bl2;
	    r2=b;
	  }
	}
	
      }else{
	bl1=l1;br2=r2;
	l1=b;r2=b;
	if(bl1!=l1){
	if(l1==3||l1==6||l1==9){
	  if(r1==1||r1==2||r1==4||r1==7||r1==8) v1++;
	}else if(l1==2||l1==8){
	  if(r1==1||r1==4||r1==7) v1++;
	}
	}
	if(br2!=r2){
	if(r2==1||r2==4||r2==7){
	  if(l2==2||l2==3||l2==6||l2==8||l2==9) v2++;
	}else if(r2==2||r2==8){
	  if(l2==3||l2==6||l2==9) v2++;
	}
	}
      }
     

      
      
      
     
      if(bv1<v1) cout << "v1 " << br1 << bl1 << r1 << " " << l1 << endl;
      //if(bv2<v2) cout << "v2" << r2 << " " << l2 << endl;
    }
    //cout << v1 << v2 << endl;
    cout << min(v1,v2) << endl;
    cin >> que;
  }
  return 0;
}
