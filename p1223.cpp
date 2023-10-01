#include <iostream>
#include <algorithm>
#include <math.h>
#include<iomanip>
using namespace std;
int main(){
    int n,i,i1;
    double ans2=0;
    cin>>n;
    int list[n][2],plist[n];
    for (i=0;i<n;i++){cin>>list[i][0];list[i][1]=i+1;plist[i]=list[i][0];}
    sort(plist,plist+n);
    //ans2
    for (i=0;i<n;i++){ans2+=plist[i]*(n-i-1);}
    ans2=round(ans2/n*100)/100;
    //out
    for (i=0;i<n;i++){
        for (i1=0;i1<n;i1++){
            if (list[i1][0]==plist[i]){
                cout<<list[i1][1];
                if (i!=n-1){cout<<" ";}
                list[i1][0]=0;
                break;
            }
        }
    }
    cout<<endl;
    cout<<fixed<<setprecision(2)<<ans2<<endl;
    return 0;
}
