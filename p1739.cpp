#include <iostream>
#include <string>
using namespace std;
int main(){
    string in,duibi="()@";
    int i,llen=0,rlen=0;
    bool ans=true;
    cin>>in;
    for (i=0;i<=in.size();i++){
        if (in[i]==duibi[0]){llen++;}
        else if (in[i]==duibi[1]){rlen++;}
        if (rlen>llen){ans=false;}
        if (in[i]==duibi[2]){break;}
    }
    if (llen!=rlen){ans=false;}
    if (ans){cout<<"YES"<<endl;}
    else{cout<<"NO"<<endl;}
    return 0;
}