#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string A,B;
int a[2010],b[2010],c[4020],i,j;
int main(){
    cin>>A>>B;
    int len=A.length()+B.length()+1;
    for (int i=A.length()-1;i>=0;i--){
        a[A.length()-i]=A[i]-'0';
    }
    for (int i=B.length()-1;i>=0;i--){
        b[B.length()-i]=B[i]-'0';
    }
    for (i=1;i<=A.length();i++){
        for (j=1;j<=B.length();j++){
            c[i+j-1]+=a[i]*b[j];
        }
    }
    for (int i=0;i<len;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while (c[len]==0){len--;}
    for (i=max(1,len);i>=1;i--){
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}