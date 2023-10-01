#include <iostream>
using namespace std;
int list[20010][20010],n,i,j,j1,a,b,g,k,x,y;
int main(){
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>a>>b>>g>>k;
        for (j=a;j<=g;j++){
            for (j1=b;j1<=k;j1++){
                list[j][j1]=i;
            }
        }
    }
    cin>>x>>y;
    if (list[x][y]!=0){cout<<list[x][y]<<endl;}
    else{cout<<-1<<endl;}
    return 0;
}