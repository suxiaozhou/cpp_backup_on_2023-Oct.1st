#include <iostream>
using namespace std;
#define y 1000
int a,i,m,j,k,n[y],o[y],p;
int len(int list[]){
    for (int k=y-1;k>=0;k--){
        if (list[k]!=0){
            return k+1;
        }
    }
    return 0;
}
int main(){
    n[0]=0;o[0]=1;
    cin>>a;
    for (i=a;i>=1;i--){
        for (m=i;m>=1;m--){
            //o*=m;
            for (j=0;j<len(o);j++){
                o[j]=o[j]*m;
            }
            for (j=0;j<len(o);j++){
                o[j+1]+=o[j]/10;
                o[j]=o[j]%10;
            }
        }
        //n+=o;
        for (int j=0;j<=max(len(n),len(o));j++) {
            n[j]+=o[j];
            n[j+1]+=n[j]/10;
            n[j]%=10;
        }
        //o=1;
        for (int j=len(o)-1;j>0;j--){o[j]=0;}o[0]=1;
    }
    for (i=len(n)-1;i>=0;i--){cout<<n[i];}cout<<endl;

    return 0;
}