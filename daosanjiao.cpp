#include <iostream>
using namespace std;
int main(){
    int n,i,num,maxnum,m,tabnum,tab,p;
    cin>>n;
    int list[n];
    num=2*n-1
    for (i=num;i>=1;i=i-2){
        num=i;
        list[i-1]=num;
    }
    maxnum=list[n-1];
    for (m=n-1;m>0;m--)
        tabnum=(maxnum-list[m-1])/2;
        for (tab=1;tab<=tabnum;tab++)
            cout<<' ';
        for (p=1;p<=list[m-1];p++)
            cout<<'#';
        cout<<'/n';
    return 0;
}