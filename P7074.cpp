#include <bits/stdc++.h>
using namespace std;
int li[1010][1010], n, m;
long long dp[1010][1010], up[1010][1010], down[1010][1010];

long long max_(long long a, long long b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	//freopen("P7074_2.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> li[j][i];
		}
	}
	swap(n, m); //做一次调换
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			dp[i][j] = up[i][j] = down[i][j] = -1e18;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			up[i][j] = max_(up[i][j - 1], dp[i - 1][j]) + li[i][j];
			if (i == 1 && j == 1) {
				up[i][j] = li[i][j];
			}
			dp[i][j] = up[i][j];
		}
		for (int j = m; j >= 1; j--) {
			down[i][j] = max_(down[i][j + 1], dp[i - 1][j]) + li[i][j];
			if (i == 1 && j == 1) {
				down[i][j] = li[i][j];
			}
			dp[i][j] = max_(dp[i][j], down[i][j]);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}