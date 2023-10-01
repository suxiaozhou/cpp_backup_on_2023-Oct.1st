#include <bits/stdc++.h>
using namespace std;
int n, li[5010], ans = 0, f[5010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> li[i];
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (li[j] < li[i]) {
				f[i] = max(f[i], f[j] + 1);
			}
		}
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}

