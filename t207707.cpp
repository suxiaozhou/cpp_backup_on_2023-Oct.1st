#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,l[26],max=1,min=100,k,i;
    bool flag=true;
    string a;
    cin>>a;
    //
    for (i=0;i<a.size();i++){l[a[i]-97]++;}
    for (i=0;i<26;i++){
        if(l[i]>max){max=l[i];}
        if (l[i]!=0 && l[i]<min){min=l[i];}
    }
    k=max-min;
    for (i=2;i<k;i++){if(k%i==0){flag=false;}}
    if (flag){cout<<"Lucky Word"<<'\n'<<k<<endl;}
    else{cout<<"No Answer"<<'\n'<<0<<endl;}
    return 0;
}