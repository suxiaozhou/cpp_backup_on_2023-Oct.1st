#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,m;
    double num=0;
    cin>>n;
    cin>>m;
    for (int i=n;i<=m;i++)
        num=num+1/pow(i,2);
    num=num*pow(10,5);
    num=round(num);
    num=num/pow(10,5);
    cout<<num<<endl;
    return 0;
}