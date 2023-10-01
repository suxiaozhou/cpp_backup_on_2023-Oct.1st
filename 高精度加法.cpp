#include <iostream>
#include <string>
#include <algorithm>
#define maxn 520
using namespace std;
int a[maxn], b[maxn], c[maxn];
int main() {
    string A, B;
    cin >> A >> B;
    int len = max(A.length(), B.length());
    for (int i = A.length() - 1, j = 1; i >= 0; i--, j++)
        a[j] = A[i] - '0';
    for (int i = B.length() - 1, j = 1; i >= 0; i--, j++)
        b[j] = B[i] - '0';
    for (int i = 1; i <= len; i++) {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }
    if (c[len + 1])
        len++;
    for (int i = len; i >= 1; i--)
        cout << c[i];
}