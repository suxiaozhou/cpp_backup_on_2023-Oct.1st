#include <iostream>
using namespace std;
int main(){
    long long n;
    int i,i2;
    bool d;
    cin>>n;
    for (i=2;i<=n;i++){
        d=true;
        for (i2=2;i2<i;i2++){
            if (i%i2==0){
                d=false;
            }
        }
        if (d&&n%i==0){
            cout<<n/i<<endl;
            break;
        }
    }
    return 0;
}