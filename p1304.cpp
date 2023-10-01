#include <iostream>
using namespace std;
int main(){
    int n,i,zhishu[1230],len=1,p;
    bool d;
    cin>>n;
    for (i=2;i<=n;i++){
        d=true;
        for (int i1=1;i1<i;i1++){
            for (int i2=1;i2<i;i2++){
                if (i1*i2==i){
                    d=false;
                }
            }
        }
        if (d){
            zhishu[len]=i;
            len++;
        }
    }
    for (i=4;i<=n;i+=2){
        for (int i1=1;i1<i;i1++){
            for (int i2=1;i2<i;i2++){
                if (zhishu[i1]+zhishu[i2]==i && p!=i){
                    cout<<i<<"="<<zhishu[i1]<<"+"<<zhishu[i2]<<endl;
                    p=i;
                }
            }
        }
    }
    return 0;
}