#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double n,a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    n=a/b;
    n=n*pow(10,c);
    n=round(n);
    n=n/pow(10,c);
    cout<<n<<endl;
    return 0;
}