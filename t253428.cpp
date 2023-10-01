#include <iostream>
using namespace std;

char h_name[6],z_name[6];
int main(){
    int i,i1,c=1,c1=1;
    cin>>h_name>>z_name;
    for (i=0;i<6;i++){
        if(h_name[i]!='\0'){
            c*=h_name[i]-'A'+1;
        }
    }
    c%=47;

    for (i=0;i<6;i++){
        if(z_name[i]!='\0'){
            c1*=z_name[i]-'A'+1;
        }
    }
    c1%=47;
    
    if (c==c1){
        cout<<"GO"<<endl;
    }
    else{
        cout<<"STAY"<<endl;
    }
    return 0;
}