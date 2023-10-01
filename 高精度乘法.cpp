#include<iostream>
#include<cstdio>
#include<string>
const int maxn = 4010;
using namespace std;
int a[maxn], b[maxn], c[maxn];
int main() {
  // 第一步
    string A,B;
    cin>>A>>B;
    int lena=A.length(),lenb=B.length();
    for (int i=lena-1;i>=0;i--){
        a[lena-i]=A[i]-'0';
    }
    for (int i=lenb-1;i>=0;i--){
        b[lenb-i]=B[i]-'0';
    }
  // 第二步
    for (int i=1;i<=lena;i++){
        for (int j=1;j<=lenb;j++){
           c[i+j-1]+=a[i]*b[j];
        }
    }
  // 第三步
    int len=lena+lenb;
    for (int i=1;i<=len;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
  // 第四步
    while (c[len]==0){
        len--;
    }
    for (int i=max(1,len);i>=1;i--){
        cout<<c[i];
    }
    return 0;
}