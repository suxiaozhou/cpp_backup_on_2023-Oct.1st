#include <iostream>
using namespace std;
bool pop(int n,int w){
    int i;
    bool p=false;
    for (i=0;i<n;i++){if (w[i]==n){p=true;}}
    return p;
}
int main(){
    int n,i,i1,max[3]={0,0,0,0};
    cin>>n;
    int list[n][3],/*ÆúÓÃ*/banli[n];
    char ansl[n];
    for (i=0;i<n;i++){cin>>list[i][3]>>list[i][0]>>list[i][1]>>list[i][2];}
    //
    for (i1=0;i1<n;i++){
        for (i=0;i<n,!pop(i,banli);i++){
            bool flag=false;
            if (list[0]>max[0]){flag=true;}
            else if (list[1]>max[1]){flag=true;}
            else if (list[2]>max[2]){flag=true;}
            if (flag){max[0]=list[0];max[1]=list[1];max[2]=list[2];max[3]=i;max[4]=list[i][3];}
        }
        banli[i1]=max[3];
        ansl[i1]=max[4];
    }
    //
    for (i=0;i<n;i++){cout<<ansl[i]<<endl;}
    return 0;
}