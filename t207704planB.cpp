#include <iostream>
using namespace std;
int main(){
    int n,i,i1;
    cin>>n;
    int z[n][n];
    for (i=n;i>1;i--){
        for (i1=n;i1>1;i1--){
            z[i][i1]=i;
            z[i1][i]=i;
        }
    }
    for (i=0;i<n;i++){
        for (i1=0;i1<n;i1++){
            cout<<z[i][i1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}