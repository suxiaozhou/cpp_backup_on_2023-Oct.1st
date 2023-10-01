#include <iostream>
#include <string>
using namespace std;
int main(){
    int i,i1,q,boy=0,girl=0;
    string s;
    cin>>s;
    for (i=0,q=s.length();i<q-2;i++){
        if (s[i]=='b'||s[i+1]=='o'||s[i+2]=='y'){
            boy++;
        }
    }
    for (i=0,q=s.length();i<q-3;i++){
        if (s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l'){
            girl++;
        }
    }
    cout<<boy<<"\n"<<girl<<endl;
    return 0;
}