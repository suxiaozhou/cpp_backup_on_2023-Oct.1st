/*
条件：
一群兔子，一对老兔子每个月生一对小兔子，每个小兔子过一个月
变成老兔子，兔子不会死亡。
问：
若干月后，共有多少只兔子？？
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long list[1000];
    int m,p;
    cin>>m;
    //第一月第二月都为1
    list[1]=list[2]=1;
    //模拟兔子
    for (p=3;p<=m;p++)//三月开始，m月截止。
        list[p]=list[p-1]+list[p-2];
        //现有等于老兔子加新兔子
    //print mod
    for (p=1;p<=m;p++)
        cout<<list[p]<<endl;
    return 0;
}