#include <iostream>
using namespace std;
int main(){
    int list[110][110],i,i1,i2,l,l1,k,x[8]={-1,-1,-1,0,0,1,1,1},y[8]={-1,0,1,-1,1,-1,0,1};
    char r;
    cin>>l>>l1;
    for (i=0;i<l;i++){
        for (i1=0;i1<l1;i1++){
            cin>>r;
            if (r=='*'){
                list[i][i1]=11;
            }
            else if (r=='?'){
                list[i][i1]=10;
            }
        }
    }
    for (i=0;i<l;i++){
        for (i1=0;i1<l1;i1++){
            if (list[i][i1]==10){
                k=0;
                for (i2=0;i2<8;i2++){
                    if (!(i+x[i2]<0||i1+y[i2]<0)){
                        if (list[i+x[i2]][i1+y[i2]]==11){
                            k++;
                        }
                    }
                }
                cout<<k;
            }
            if (list[i][i1]==11){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
} 