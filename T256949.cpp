#include <iostream>
#include <string>
using namespace std;
int a[5010],c[5010],i;
long long b,p=0;
string A;
int main(){
    cin>>A>>b;
    for (i=1;i<=A.length();i++){
        a[i]=A[i-1]-'0';
    }
    for (i=0;i<=A.length();i++){
        p=p*10+a[i];
        c[i]=p/b;
        p%=b;
    }
    int flag=0;
    for (i=0;i<=A.length();i++){
        if (c[i]!=0){
            flag=1;
        }
        if (flag==1){
            cout<<c[i];
        }
        if ((!flag)&&i==A.length()){cout<<0;}
    }
    cout<<endl;
    return 0;
}