#include<iostream>
#include<cmath>
#include<string>
using namespace std;
const int maxn = 5050;
int a[maxn], b, c[maxn], p, len,i;
string A;
int main() {
    // 第一步：读入字符串 A 和 数字 b
    // len 赋值为 A 的长度
    // 循环，将 A[i-1] 的字符转成数字，放到 a[i] 中
    cin>>A>>b;
    len=A.length();
    for (i=1;i<=len;i++){
      a[i]=A[i-1]-'0';
    }

    // 第二步：循环
        // 临时数字右边拼接上 a[i]
        // 商 c[i] 是临时数字除以 b 的值
        // 临时数字变为余数
    for (i=0;i<=len;i++){
      p=p*10+a[i];
      c[i]=p/b;
      p=p%b;
    }

    // 第三步：输出
    // flag 的值赋值为 0
    // 对于商的每一位，进行循环输出：
        // 如果这一位是非零，flag 赋值为 1
        // 如果 flag 是 1，则输出这一位]
    int flag=0;
    for (i=0;i<=len;i++){
      if (c[i]!=0){
        flag=1;
      }
      if (flag==1){
        cout<<c[i];
      }
    }
    cout<<endl;
    return 0;
}