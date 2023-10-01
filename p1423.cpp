#include <iostream>
using namespace std;
int main(){
    double n,speed=2;
    bool flag=true;
    cin>>n;
    for (int i=0;flag;i++){
        n-=speed;
        speed*=0.98;
        if (n<0){flag=false;cout<<i+1<<endl;}
    }
    return 0;
}