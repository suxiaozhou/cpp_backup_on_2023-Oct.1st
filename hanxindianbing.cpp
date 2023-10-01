#include <iostream>
using namespace std;
int main(){
    int ttn,ftn,stn,i;
    bool cando=true;
    cin>>ttn;
    cin>>ftn;
    cin>>stn;
    //过滤
    if (ttn>=3||ftn>=5||stn>=7){
        cout<<'格式错误'<<endl;
    }
    else{
        //计算
        for (i=10;i<100;i++)
            if (i%3==ttn && i%5==ftn && i%7==stn){
                cando=false;
                cout<<i<<endl;
            }
    }
    if (cando){
        cout<<'No answer'<<endl;
    }
    return 0;
}