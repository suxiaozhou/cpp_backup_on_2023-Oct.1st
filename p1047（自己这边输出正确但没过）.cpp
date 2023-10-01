#include <iostream>
using namespace std;
int main(){
    int l,m,i,i1,ans,c1,c2;
    cin>>l>>m;
    bool anslist[l];
    //
    for (i=0;i<l;i++){anslist[i]=true;}
    for (i=0;i<m;i++){
        cin>>c1>>c2;
        for (i1=c1;i1<=c2;i1++){anslist[i1]=false;}}
    for (i=0;i<l;i++){if (anslist[i]){ans++;}}
    //
    cout<<ans<<endl;
    return 0;
}