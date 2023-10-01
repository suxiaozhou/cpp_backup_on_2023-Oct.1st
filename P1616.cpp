#include <bits/stdc++.h>
using namespace std;
long long t, m, dp[10000010];
int v[10000010], ti[10000010];

long long max_(long long a, long long b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> ti[i] >> v[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = ti[i]; j <= t; j++) {
			dp[j] = max_(dp[j - ti[i]] + v[i], dp[j]);
		}
	}
	cout << dp[t] << endl;
	return 0;
}

