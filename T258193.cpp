#include <bits/stdc++.h>
using namespace std;
unsigned int n;

int main() {
	cin >> n;
	cout << (n << 16) + (n >> 16) << endl;
	return 0;
}