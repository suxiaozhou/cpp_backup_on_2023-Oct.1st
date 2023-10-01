#include <iostream>
using namespace std;
int main(){
    int l,i,i1,zh=0,list[8000],len=0;
    bool flag1;
    cin>>l;
    for (i=2;zh<l&&zh+i<=l;i++){
        //判断质数
        flag1=true;
        for (i1=2;i1<i;i1++){if (i%i1==0){flag1=false;}}
        //
        if (flag1){list[len]=i;len++;zh+=i;}//说明是个质数
    }
    //
    for (i=0;i<len;i++){cout<<list[i]<<endl;}
    cout<<len<<endl;
    return 0;
}