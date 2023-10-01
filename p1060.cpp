#include <iostream>
using namespace std;
int main(){
    int m,s,i,l=0;
    cin>>m;
    cin>>s;
    int list[s][2];
    for (i=1;i<=s;i++){
        cin>>list[i][1];
        cin>>list[i][2];
    }
    for (i=5;i>=1;i--){
        for (int i1=1;i1<=s;i1++){
            if (list[i1][2]=i && m-list[i1][1]>=0){
                l+=list[i1][1]*list[i1][2];
                cout<<list[i1][1]<<endl;
                m-=list[i1][1];
            }
        }
    }
    cout<<l<<endl;
    return 0;
}