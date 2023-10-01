#include <iostream>
using namespace std;
int main(){
    int al[11],h,i,n=0;
    const int c=30;
    for (i=1;i<=10;i++)
        cin>>al[i];
    cin>>h;
    for (i=1;i<=10;i++)
        if (h+c>=al[i])
            n++;
    cout<<n<<endl;
    return 0;
}