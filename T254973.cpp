#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int i,j,len,a[510],b[510],c[515];
int main(){
    string ina,inb;
    cin>>ina;cin>>inb;
    len=max(ina.length(),inb.length());
    for (i=0,j=ina.length()-1;i<ina.length();i++,j--){
        a[i]=ina[j]-'0';
    }
    for (i=0,j=inb.length()-1;i<inb.length();i++,j--){
        b[i]=inb[j]-'0';
    }
    for (i=0;i<len;i++){
        c[i]+=a[i]+b[i];
        c[i+1]=c[i]/10;
        c[i]%=10;
    }
    if (c[len]){
        len++;
    }
    for (i=len-1;i>=0;i--){
        cout<<c[i];
    }
    cout<<endl;
    return 0;
}
