#include <iostream>
using namespace std;
int main(){
    int w,s,y,ans=0;
    cin>>w>>s>>y;
    bool n1,n2,n3;
    if (w<60){n1=true;}
    if (s<60){n2=true;}
    if (s<60){n3=true;}
    if (n1||n2||n3){ans=1;}
    if (n1&&n2){ans=0;}
    if (n1&&n3){ans=0;}
    if (n3&&n2){ans=0;}
    cout<<ans<<endl;
    return 0;
}