#include <iostream>
#include <string>
using namespace std;
int i,j,list[10]={0,2,3,4,6,7,8,9,10},ans=0;
string in;
int main(){
    cin>>in;
    for (i=1;i<=9;i++){
        ans+=(in[list[i-1]]-'0')*i;
    }
    ans%=11;
    if (ans!=10){
        if (ans==in[12]-'0'){cout<<"Right"<<endl;}
        else{
            for (i=0;i<12;i++){cout<<in[i];}
            cout<<ans<<endl;
        }
    }
    else{
        if (in[12]=='X'){cout<<"Right"<<endl;}
        else{
            for (i=0;i<12;i++){cout<<in[i];}
            cout<<'X'<<endl;
        }
    }
    return 0;
}