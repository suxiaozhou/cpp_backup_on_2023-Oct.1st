#include <iostream>
using namespace std;
int main(){
    int n,i,list[10000],l=0,max=0;
    cin>>n;
    for (i=1;i<=n;i++){
        cin>>list[i];
        if (list[i]-1==list[i-1]){l++;}
        if (l>max){max=l;}
        if (list[i]-1!=list[i-1]){l=0;}
    }
    if(max>=1){max++;}
    cout<<max<<endl;
    return 0;
}