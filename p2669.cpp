#include <iostream>
using namespace std;
int main(){
    int i,i1,k,day1=0,m=0;
    cin>>k;
    for (i=1;day1<k;i++){for (i1=1;i>=i1&&day1<k;i1++,day1++,m+=i){}}
    cout<<m<<endl;
    return 0;
}