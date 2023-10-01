#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[10100], b[10100], c[10100];
int main() {
    string A, B,t;
    cin >> A >> B;
    if (A==B){cout<<"0"<<endl;return 0;}
    else if(A.length()<B.length()||(A.length()==B.length()&&A<B)){
        t=A;A=B;B=t;
        cout<<"-";
    }

    int len = max(A.length(), B.length());
    for (int i = A.length() - 1, j = 1; i >= 0; i--, j++)
        a[j] = A[i] - '0';
    for (int i = B.length() - 1, j = 1; i >= 0; i--, j++)
        b[j] = B[i] - '0';
    for (int i = 1; i <= len; i++) {
        c[i] = c[i] + a[i] - b[i];
        if(c[i] < 0) {
            c[i] += 10;
            c[i + 1] -= 1;
        }
    }
    int len2;
    for(len2 = len; len2 >= 1; len2--) 
        if(c[len2] != 0)
            break;
    for (int i = len2; i >= 1; i--)
        cout << c[i];
    return 0;
}