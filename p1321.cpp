#include <iostream>
#include <string>
using namespace std;
int jianduo(string in,string str,string bname,string in1){
    if (in==str&&in1==bname){return -1;}
    else{return 0;}
}
int main(){
    string b="o",o="y",g="i",i="r",r="l",in,z;
    string biao="boygirl";
    int ansb,ansg,i1;
    cin>>in;
    for (i1=0;i1<in.size();i1++){
        if (in[i1]==biao[0]||in[i1]==biao[1]||in[i1]==biao[2]){
            ansb++;
            ansb=ansb+jianduo(in[i1],biao[0],b,in[i1+1])+jianduo(in[i1],biao[1],o,in[i1+1]);
        }
        if (in[i1]==biao[3]||in[i1]==biao[4]||in[i1]==biao[5]||in[i1]==biao[6]){
            ansg++;
            ansg=ansg+jianduo(in[i1],biao[3],g,in[i1+1])+jianduo(in[i1],biao[4],i,in[i1+1])+jianduo(in[i1],biao[5],r,in[i1+1]);
        }
    }
    cout<<ansb<<"\n"<<ansg<<endl;
    return 0;
}