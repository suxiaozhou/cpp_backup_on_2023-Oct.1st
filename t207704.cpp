#include <iostream>
using namespace std;
int main(){
    int n,i,i1,i2;
    cin>>n;
    int z[n][n];
    for (i=1;i<=n;i++){
        for (i1=i;i1<=n;i1++){
            for (i2=i;i2<=n;i2++){
                z[i1][i2]=i;
            }
        }
    }
    for (i=1;i<=n;i++){
        for (i1=1;i1<=n;i1++){
            if (i1!=1){cout<<" ";}
            cout<<z[i][i1];
        }
        cout<<endl;
    }
    return 0;
}