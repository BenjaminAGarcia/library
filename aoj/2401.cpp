#include<iostream>
#include<string>
#include<vector>
#define MAX 11
using namespace std;
bool o;
void rec(string s){
  if(!o) return;
  //cout << s << endl;
  while(1){
    bool f=false;
    int p;
    
    while(s.find("-0")!=-1){
      p=s.find("-0");
      s[p]='1';s[p+1]=' ';
      f=true;
    }
    while(s.find("-1")!=-1){
      p=s.find("-1");
      s[p]='0';s[p+1]=' ';
      f=true;
    }
    while(s.find("(0*0)")!=-1){
      p=s.find("(0*0)");
      s[p]='0';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(0*1)")!=-1){
      p=s.find("(0*1)");
      s[p]='0';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(1*0)")!=-1){
      p=s.find("(1*0)");
      s[p]='0';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(1*1)")!=-1){
      p=s.find("(1*1)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(0+0)")!=-1){
      p=s.find("(0+0)");
      s[p]='0';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(0+1)")!=-1){
      p=s.find("(0+1)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(1+0)")!=-1){
      p=s.find("(1+0)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    while(s.find("(1+1)")!=-1){
      p=s.find("(1+1)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';
      f=true;
    }
    
    while(s.find("(0->0)")!=-1){
      p=s.find("(0->0)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';s[p+5]=' ';
      f=true;
    }
    while(s.find("(0->1)")!=-1){
      p=s.find("(0->1)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';s[p+5]=' ';
      f=true;
    }
    while(s.find("(1->0)")!=-1){
      p=s.find("(1->0)");
      s[p]='0';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';s[p+5]=' ';
      f=true;
    }
    while(s.find("(1->1)")!=-1){
      p=s.find("(1->1)");
      s[p]='1';s[p+1]=' ';s[p+2]=' ';s[p+3]=' ';s[p+4]=' ';s[p+5]=' ';
      f=true;
    }
    
    if(f){
      string b;
      for(int i=0;i<s.size();i++) if(s[i]!=' ') b+=s[i];
      s=b;
    }else{
      if(s[0]!=s[2]) o=false;
      return;
    }
  }
}
bool fi;
vector<int> v[11];
void init(int n,string s){
  int i,j;
  if(fi){
    for(j=0;j<MAX;j++) v[j].clear();
    for(i=0;i<s.size();i++){
      for(j=0;j<MAX;j++){
	if(s[i]=='a'+j) {
	  s[i]='0'+(n>>j&1);
	  v[j].push_back(i);
	}
      }
    }
    fi=false;
  }else{
    for(i=0;i<MAX;i++){
      for(j=0;j<v[i].size();j++){
	s[v[i][j]]='0'+(n>>i&1);
      }
    }
  }
  //cout << s << endl;
  rec(s);
  if(!o) return;
}
int main(){
  string s;
  while(cin >> s,s!="#"){
    o=true;
    int i;
    fi=true;
    for(i=0;i<s.size();i++){
      if(s[i]=='T') s[i]='1';
      if(s[i]=='F') s[i]='0';
    }
    for(i=0;i<(1<<MAX);i++)
      if(o) init(i,s);
      else break;
    cout << (o?"YES":"NO") << endl;
  }
  return 0;
}
