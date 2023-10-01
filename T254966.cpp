#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,i,i1,ansn;
    string l,ans="0";
    cin>>n;
    for (i=0;i<n;i++){
        cin>>l;
        for (i1=l.length();i1<110;i1++){l='0'+l;}
        if (l>ans){
            ans=l;
            ansn=i+1;
        }
    }
    cout<<ansn<<endl;
    for (i=0;i<110;i++){
        if (ans[i]!='0'){
            break;
        }
    }
    for (i1=i;i1<110;i1++){
        cout<<ans[i1];
    }
    cout<<endl;
    return 0;
}