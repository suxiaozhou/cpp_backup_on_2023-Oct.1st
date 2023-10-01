#include <iostream>
using namespace std;
#include <algorithm>
int main(){
    int n,i,l=0,l1=0;
    cin>>n;
    int list[n];
    for (i=0;i<n;i++){cin>>list[i];}
    sort(list,list+n);
    for (i=0;i<n;i++){if (list[i]==list[i+1]){list[i]=0;l1++;}l++;}
    cout<<l-l1<<endl;
    for (i=0;i<l;i++){if (list[i]!=0){cout<<list[i]<<" ";}}
    return 0;
}