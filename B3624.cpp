#include <bits/stdc++.h>
using namespace std;
int n, l, r, w[80], li[80], ans;

void dfs(int c) {
	int sum = 0;
	for (int i = 1; i <= c - 1; i++) {
		if (li[i]) {
			sum += w[i];
		}
	}
	if (sum > r) {
		return;
	}
	if (c == n + 1) {
		if (sum <= r && sum >= l) {
			ans++;
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		li[c] = i;
		dfs(c + 1);
	}
	return;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}