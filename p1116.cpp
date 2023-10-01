#include <iostream>
using namespace std;
int main(){
    int n,i,r,c=0,n1;
    cin>>n;
    int list[n];
    for (i=1;i<=n;i++){
        cin>>list[i];
    }
    for (i=1;i<=n;i++){
        for (r=1;r<=i;r++){
            //x前面有y个要跟他绕的
            if (list[r]>list[i]){
                c++;
            }

        }
    }
    cout<<c<<endl;
    return 0;
}