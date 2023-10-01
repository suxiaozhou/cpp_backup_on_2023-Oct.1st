#include <bits/stdc++.h>
using namespace std;
#define int long long
int k, n, d, e;

signed main() {
	cin >> k;
	for (int i = 1; i <= k; i++) {
		bool flag = 0;
		cin >> n >> d >> e;
		int l = 0;
		int m = n - e * d + 2;
		int r = m;
		while (r - l > 1) {
			int p = (l + r) / 2;
			int q = m - p;
			if (p * q < n) {
				l = p;
			} else if (p * q > n) {
				r = p;
			} else if (n / p == q) {
				cout << p << " " << q << endl;
				flag = 1;
				break;
			}
			//cerr << l << " " << r << endl;
		}
		if (!flag) {
			cout << "NO" << endl;
		}
	}
	return 0;
}

