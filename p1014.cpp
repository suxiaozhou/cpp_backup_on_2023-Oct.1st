#include <iostream>
using namespace std;
int main(){
    //init,in
    int i,l=0,n,g,num0,ans0,ans1;
    cin>>n;
    //计算在第几行l
    for (i=0;l<n;n=n-l,l++){}
    //计算在第几个
    ///如果在双数行
    if (l%2==0){
        num0=l+1;
        ans0=n;
        ans1=num0-ans0;
    }
    ///在单数行
    else{
        num0=l+1;
        ans1=n;
        ans0=num0-ans1;
    }
    //out
    cout<<ans0<<"/"<<ans1<<endl;
    return 0;
}