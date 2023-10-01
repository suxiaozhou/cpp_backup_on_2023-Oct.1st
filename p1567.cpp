#include <iostream>
using namespace std;
int main(){
    int max=0,n,day=0,i,in,lin=1000000000;
    cin>>n;
    for (i=0;i<n;i++){
        cin>>in;
        if (in>lin){day++;}
        else{day=0;}
        if (day>max){max=day;}
        lin=in;
    }
    cout<<max+1<<endl;
    return 0;
}