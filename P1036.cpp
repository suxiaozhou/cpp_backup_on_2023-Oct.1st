#include <bits/stdc++.h>
using namespace std;
int n, k, x[50], use[50];
long long ans = 0;

bool is_prime_num(int pnum) {
	bool is_p = true;
	for (int i = 2; i < pnum / 2; i++) {
		if (pnum % i == 0) {
			is_p = false;
		}
	}
	return is_p;
}

void dfs(int pos, int c, int sum) {
	if (pos == k + 1) {
		if (is_prime_num(sum)) {
			ans++;
		}
		return;
	}
	for (int i = c + 1; i <= n; i++) {
		if (!use[i]) {
			use[i] = 1;
			dfs(pos + 1, i, sum + x[i]);
			use[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}