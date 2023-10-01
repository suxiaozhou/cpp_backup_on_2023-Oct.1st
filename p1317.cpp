#include <iostream>
using namespace std;
int main(){
    int n,i,ans=0;
    bool flag=false;
    cin>>n;
    int list[n+1];
    /****************************×¢Òâ×¢Òâ×¢Òâ£¡£¡£¡£¡
    list[0]=0;
    ************************/
    for (i=1;i<=n;i++){cin>>list[i];}
    for (i=1;i<=n;i++){
        if (list[i]<list[i-1]){
            flag=true;
        }
        if (list[i]>list[i-1]&&flag){
            flag=false;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}