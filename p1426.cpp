#include <iostream>
using namespace std;
int main(){
    int s,x,i,flag=1;
    double speed=7,c=0.98;
    cin>>s>>x;
    while (flag){
        if (speed-s-x<1){
            flag=0;
            if (speed*c<=2*x){cout<<"y"<<endl;}//嘎了
            else{cout<<"n"<<endl;}//差点嘎了
        }
        speed=speed*c;//累了
    }
    return 0;
}