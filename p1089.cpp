#include <iostream>
using namespace std;
int main(){
    const int m=300,lixi=1.2;
    int cost[12],i,money,lmmoney=0;
    int qianm=0,have=0;
    for(i=1;i<=12;i++){
        cin>>cost[i];
    }
    for(i=1;i<=12;i++){
        money=lmmoney+m-cost[i];
        if (money<0){
            cout<<-i<<endl;
            qianm=1;
            break;
        }
        else{
            lmmoney=money%100;
            have+=money-lmmoney;
        }
    }
    if (qianm==0){
        have*=lixi;
        cout<<have+money<<endl;
    }
    return 0;
}