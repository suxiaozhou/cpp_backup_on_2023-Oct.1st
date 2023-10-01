#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
int n, p, q;
int fa[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Union(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	if (fx != fy) {
		fa[fx] = fy;
	}
}

int main() {
	cin >> n >> p >> q;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < p; i++) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		Union(u, v);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (find(i) != find(j)) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}