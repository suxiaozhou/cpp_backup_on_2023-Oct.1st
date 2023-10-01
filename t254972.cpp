#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int i,j,len,a[10100],b[10100],c[10110];
int main(){
    string ina,inb,t;
    cin>>ina;cin>>inb;
    len=max(ina.length(),inb.length());
    if (ina==inb){cout<<"0"<<endl;return 0;}
    else if(ina.length()<inb.length()||(ina.length()==inb.length()&&ina<inb)){
        t=ina;ina=inb;inb=t;
        cout<<"-";
    }
    for (i=0,j=ina.length()-1;i<ina.length();i++,j--){
        a[i]=ina[j]-'0';
    }
    for (i=0,j=inb.length()-1;i<inb.length();i++,j--){
        b[i]=inb[j]-'0';
    }
    for (i=0;i<len;i++){
        c[i]+=a[i]-b[i];
        if (c[i]<0){
            c[i+1]--;
            c[i]+=10;
        }
    }
    for (i=len-1;i>=1;i--,len--){
        if (c[i]!=0){break;}
    }
    for (int i = len-1; i >= 0; i--)
        cout << c[i];
    return 0;
}