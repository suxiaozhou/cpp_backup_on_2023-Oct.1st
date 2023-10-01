#include <iostream>
using namespace std;
int main(){
    int in,i;
    char s,out,m[12]={'January','February','March','April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'};
    cin>>s>>in;
    for (i=0;i<12;i++){
        if (m[i]==s){
            out=m[(i+in)%12];
        }
    }
    cout<<out<<endl;
    return 0;
}