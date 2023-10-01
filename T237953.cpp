#include <bits/stdc++.h>
using namespace std;

struct typ {
	int time, value;
} li[110];
int T, M, vis[110], ans = 0;

int dfs(int time, int v) {
	if (time > T) {
		return 1;
	}
	for (int i = 1; i <= M; i++) {
		if (vis[i]) {
			continue;
		}
		vis[i] = 1;
		if (dfs(time + li[i].time, v + li[i].value)) {
			ans = max(v, ans);
		}
		vis[i] = 0;
	}
	return 0;
}

int main() {
	cin >> T >> M;
	for (int i = 1; i <= M; i++) {
		cin >> li[i].time >> li[i].value;
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}

