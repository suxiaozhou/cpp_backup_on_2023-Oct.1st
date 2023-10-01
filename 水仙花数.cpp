#include <cmath>
#include <iostream>
using namespace std;
int main(){
    int n,q,baiwei,shiwei,gewei,num;
    for (n=100;n<=999;n++){
        q=n%100;
        baiwei=(n-q)/100;
        gewei=q%10;
        shiwei=(q-gewei)/10;
        num=pow(baiwei,3)+pow(shiwei,3)+pow(gewei,3);
        //cout<<192<<' '<<n<<' '<<baiwei<<' '<<shiwei<<' '<<gewei<<' '<<q<<' '<<168<<' '<<num<<endl;
        if (num==n){
            cout<<n<<endl;
        }
    }
    return 0;
}

