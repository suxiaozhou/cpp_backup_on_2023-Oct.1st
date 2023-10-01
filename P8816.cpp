#include <bits/stdc++.h>
using namespace std;
int n, k, ans;

struct pos {
	int x, y;
} li[510];

void dfs(int start, int score) {
	ans = max(ans, score);
	for (int i = 1; i <= n; i++) {
		if ((li[i].x - li[start].x == 1 && li[i].y == li[start].y) || (li[i].y - li[start].y == 1 && li[i].x == li[start].x)) {
			dfs(i, score + 1);
		}
	}
	return;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> li[i].x >> li[i].y;
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 1);
	}
	ans += k;
	cout << ans << endl;
	return 0;
}

