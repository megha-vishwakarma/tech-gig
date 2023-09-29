#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int j=0;
long long p=0;
int pl=0;
for(int i=0;i<n;i++){
int a;
cin>>a;
if(j==0 && a<0){
pl++;
j++;
}
else if(a>0)j=0;
p+=abs(a);
}
cout<<p<<' '<<pl<<endl;
return 0;
}
