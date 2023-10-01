#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,m,k,i,i1,i2,l1,l2,ans=0;
    cin>>n,m,k;
    bool list[n][n],flag;
    for (i=0;i<n;i++){for (i1=0;i1<n;i1++){list[i][i1]=false;}}
    for (i=0;i<m;i++){
        cin>>l1,l2;
        for (i1=-2;i1<=2;i1++){
            for (i2=-2;i2<=2;i2++){
                flag=abs(i1)+abs(i2)<=2;
                if (flag){list[i1+l1][i2+l2]=true;}
            }
        }
    }
    for (i=0;i<k;i++){
        l1=0;
        l2=0;
        cin>>l1,l2;
        for (i1=-2;i1<=2;i1++){
            for (i2=-2;i2<=2;i2++){
                list[i1+l1][i2+l2]=true;
            }
        }
    }
    for (i=0;i<n;i++){
        for (i1=0;i1<n;i1++){
            if (!list[i][i1]){ans++;}
        }
    }
    cout<<ans<<endl;
    //
    return 0;
}