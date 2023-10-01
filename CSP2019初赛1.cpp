#include <bits/stdc++.h>
using namespace std;

int f(int n, int k) {
	if (k == 1 || n == 1 || n == 0) {
		//cerr << n << " " << k << endl;
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	return f(n, k - 1) + f(n - k, k);
}

int main() {
	cout << f(8, 5) << endl;
	return 0;
}

