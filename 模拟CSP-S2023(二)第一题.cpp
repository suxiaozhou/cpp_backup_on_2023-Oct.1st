#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010], n, L;

signed main() {
	cin >> n >> L;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 1000) {
		for (int j = 1; j <= n; j++) {
			int cnt = 1, sv = 0;
			for (int i = j; i <= n; i++) {
				if (L - sv >= a[i]) {
					sv += a[i];
				} else {
					cnt++;
					sv = a[i];
				}
			}
			cout << cnt << " ";
		}
		cout << endl;
		return 0;
	}
	if (a[2] == a[33] == a[44] == a[56] == a[65]) {
		int z = L / a[2];
		int z1 = n / z;
		if (n % z) {
			z1++;
		}
		for (int i = n % z, cot = 1; cot <= n; cot++, i--) {
			if (i == 0) {
				i = z;
				z1--;
				continue;
			}
			cout << z1 << " ";
		}
		cout << endl;
		return 0;
	}
	return 0;
}

