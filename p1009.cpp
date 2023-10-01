#include <iostream>
using namespace std;
int main(){
    int a,i,m;
    long long n=0,n1=0,o=1,o1=0;
    cin>>a;
    for (i=a;i>=1;i--){
        for (m=i;m>1;m--){
            o*=m;
        }
        n+=o;
        o=1;
    }
    cout<<n<<endl;
    return 0;
}