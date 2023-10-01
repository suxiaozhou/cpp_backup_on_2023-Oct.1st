#include <bits/stdc++.h>
using namespace std;
int n, m, li[1000][1000];
long long ans = -23333333;
bool vis[1000][1000];

void dfs(int x, int y, long long sum) {
	sum += li[x][y];
	if (x == n && y == m) {
		//cout << sum << endl << "*************" << endl;
		if (sum > ans) {
			ans = sum;
		}
		return;
	}
	if (x < 1 || x > n || y < 1 || y > m || vis[x][y]) {
		return;
	}
	vis[x][y] = 1;
	//cout << x << " " << y << endl;
	dfs(x + 1, y, sum);
	dfs(x - 1, y, sum);
	dfs(x, y + 1, sum);
	vis[x][y] = 0;
	return;
}

int main() {
	int i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> li[i][j];
		}
	}
	dfs(1, 1, 0);
	cout << ans << endl;
	return 0;
}

