#include <iostream>
using namespace std;
int main(){
    int n,i,b[6],ans=0,m,lt=0;
    cin>>n;
    for (i=0;i<6;i++){cin>>b[i];}
    for (i=0;i<n;i++){
        cin>>m;
        if (m==1){
            lt++;
            if (lt<3){ans+=b[0];}
            else if (lt>=3 && lt<7){ans+=b[1];}
            else if (lt>=7 && lt<30){ans+=b[2];}
            else if (lt>=30 && lt<120){ans+=b[3];}
            else if (lt>=120 && lt<365){ans+=b[4];}
            else if (lt>=365){ans+=b[5];}
        }
        else{
            lt==0;
        }
    }
    cout<<ans<<endl;
    return 0;
}