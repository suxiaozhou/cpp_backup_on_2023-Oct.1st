#include <iostream>
using namespace std;
int main()
{
    int currVal=0,val=0;
    if (std::cin>>currVal){
        int cnt=1;
        while (std::cin>>val){
            if (val==currVal){
                ++cnt;
            }
            else{
                cout<<currVal<<endl;
                cout<<cnt<<endl;
                currVal=val;
                cnt=1;
            }
        }
        cout<<currVal<<cnt<<endl;
    }
