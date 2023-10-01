#include <bits/stdc++.h>
using namespace std;
int n, m, i, ans = 0;

struct g {
	int v, s;
} st[5010];

bool cmp(g a, g b) {
	return a.v < b.v;
}

int main() {
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> st[i].v >> st[i].s;
	}
	sort(st, st + m, cmp);
	for (i = 0; i < m; i++) {
		if (st[i].s >= n) {
			ans += n * st[i].v;
			break;
		}
		ans += st[i].v * st[i].s;
		n -= st[i].s;
	}
	cout << ans << endl;
	return 0;
}