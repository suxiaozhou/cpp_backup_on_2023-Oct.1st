#include <iostream>
#include <string>
using namespace std;
int main(){
    bool flag=true;
    string a[50000],m,stop="0";
    int i,l=0;
    while (flag){
        cin>>m;
        bool flag1=true;
        if (m!=stop){
            for (i=0;i<l;i++){
                if (a[i]==m){
                    flag1=false;
                }
            }
            if (flag1){cout<<m;a[l]=m;l++;}
        }
        else{flag=false;}
    }
    return 0;
}