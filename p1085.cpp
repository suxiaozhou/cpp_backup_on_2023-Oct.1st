#include <iostream>
using namespace std;
int main(){
    int ct,bt,md[2]={0,0};
    for(int i=1;i<=7;i++){
        cin>>ct;
        cin>>bt;
        if (ct+bt>8&&ct+bt>md[1]){
            md[1]=ct+bt;
            md[0]=i;
        }
    }
    cout<<md[0]<<endl;
    return 0;
}