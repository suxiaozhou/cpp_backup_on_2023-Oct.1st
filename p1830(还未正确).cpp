#include <iostream>
using namespace std;
int main(){
    int n,m,x,y,i,i1,lun=1;
    //in
    cin>>n>>m>>x>>y;
    int bo_list[x][4],imp_area[y][4];
    for (i=0;i<x;i++){cin>>bo_list[i][0]>>bo_list[i][1]>>bo_list[i][2]>>bo_list[i][3];}
    for (i=0;i<y;i++){cin>>imp_area[i][0]>>imp_area[i][1];imp_area[i][2]=0;}
    //check
    for (i=0;i<y;i++){
        for (i1=0;i<x;i++){
            if (bo_list[i1][0]<=imp_area[i][0]&&bo_list[i1][1]>=imp_area[i][1]&&bo_list[i1][2]>=imp_area[i][0]&&bo_list[i1][3]<=imp_area[i][1]){
                imp_area[i][2]++;
                imp_area[i][3]=lun;
                lun++;
            }
        }
    }
    //out
    for (i=0;i<y;i++){
        if (imp_area[i][2]==0){cout<<"N"<<endl;}
        else{cout<<"Y"<<" "<<imp_area[i][2]<<" "<<imp_area[i][3]<<endl;}
    }
    //end
    return 0;
}