#include <iostream>
using namespace std;
int digui(int num){
    if (num<=0){
        cout<<'stop'<<endl;
    }
    else{
        cout<<num<<endl;
        digui(num-1);
    }
}
int main(){
    int in_num;
    cin>>in_num;
    digui(in_num);
    return 0;
}