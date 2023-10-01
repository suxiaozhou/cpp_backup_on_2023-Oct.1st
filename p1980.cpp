#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,i,i1,ans=0;
    string x,check;
    cin>>n;
    cin>>x;
    for (i=1;i<=n;i++){
        check=to_string(i);
        for (i1=0;i1<check.size();i1++){if (check[i1]==x[0]){ans++;}}}
        cout<<ans<<endl;
    return 0;
}