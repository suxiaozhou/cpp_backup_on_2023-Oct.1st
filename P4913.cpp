#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;

struct trees {
	int l, r;
} t[1000010];

void dfs(int spot, int step) {
	if (t[spot].l == 0 && t[spot].r == 0) {
		ans = max(ans, step);
		return;
	}
	if (t[spot].l != 0) {
		dfs(t[spot].l, step + 1);
	}
	if (t[spot].r != 0) {
		dfs(t[spot].r, step + 1);
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].l >> t[i].r;
	}
	dfs(1, 1);
	cout << ans << endl;
	return 0;
}

