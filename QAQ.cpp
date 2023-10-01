#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    int i,i1,i2,ans=0;
    cin>>s;
    for (i=0;i<s.length()-2;i++){
        if (s[i]=='Q'){
            for (i1=i+1;i1<s.length()-1;i1++){
                if (s[i1]=='A'){
                    for (i2=i1+1;i2<s.length();i2++){
                        if (s[i2]=='Q'){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}