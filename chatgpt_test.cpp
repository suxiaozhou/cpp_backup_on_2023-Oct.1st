#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m)));

	for (int i = 0; i < n; i++) {
		for (int j1 = 0; j1 < m; j1++) {
			for (int j2 = j1; j2 < m; j2++) {
				if (i > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i - 1][j1][j2]);
				}
				if (j1 > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i][j1 - 1][j2]);
				}
				if (j2 > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i][j1][j2 - 1]);
				}
				if (i > 0 && j1 > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i - 1][j1 - 1][j2]);
				}
				if (i > 0 && j2 > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i - 1][j1][j2 - 1]);
				}
				if (j1 > 0 && j2 > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i][j1 - 1][j2 - 1]);
				}
				if (i > 0 && j1 > 0 && j2 > 0) {
					dp[i][j1][j2] = max(dp[i][j1][j2], dp[i - 1][j1 - 1][j2 - 1]);
				}
				dp[i][j1][j2] += grid[i][j1] + (j1 != j2 ? grid[i][j2] : 0);
			}
		}
	}

	cout << dp[n - 1][m - 1][m - 1] << endl;

	return 0;
}
