#include <iostream>
using namespace std;
int main(){
    int k,n=0;
    double sn;
    cin>>k;
    for (sn=0;sn<=k;n++,sn=sn+1.0/n);
    cout<<n<<endl;
    return 0;
}