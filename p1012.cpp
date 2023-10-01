#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool bijiao(string a,string b){
    return a+b>=b+a;
}
int main(){
    int n,i;
    cin>>n;
    string list[n];
    for (i=0;i<n;i++){
        cin>>list[i];
    }
    sort(list,list+n,bijiao);
    for (i=0;i<n;i++){
        cout<<list[i];
    }
    cout<<endl;
    return 0;
}