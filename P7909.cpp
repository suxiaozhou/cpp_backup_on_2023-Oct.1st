#include <bits/stdc++.h>
using namespace std;
long long n,L,R;
int main(){
    cin>>n>>L>>R;
    if (R-L>=n||R%n<L%n){
        cout<<n-1<<endl;
        return 0;
    }
    cout<<R%n<<endl;
    return 0;
}