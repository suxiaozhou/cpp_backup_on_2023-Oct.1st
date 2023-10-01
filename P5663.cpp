#include <bits/stdc++.h>
using namespace std;
vector <int> link[100010];
int n, m, q, a, L, u, v;

bool bfs(int spot, int level) {
	if (level == 0) {
		if (spot == 1) {
			return 1;
		}
		return 0;
	}
	bool flag = 0;
	for (int i = 0; i < link[spot].size(); i++) {
		flag = flag || bfs(link[spot][i], level - 1);
	}
	return flag;
}

int main() {
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		link[u].push_back(v);
		link[v].push_back(u);
	}
	for (int i = 1; i <= q; i++) {
		cin >> a >> L;
		if (bfs(a, L)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}

