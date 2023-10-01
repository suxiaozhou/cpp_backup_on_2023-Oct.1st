#include <iostream>
using namespace std;
int main(){
    long long a,b,i;
    cin>>a>>b;
    if (a>b){cout<<"Error!"<<endl;return -1;}
    for (i=a;i<=b;i++){cout<<i<<endl;}
    return 0;
}