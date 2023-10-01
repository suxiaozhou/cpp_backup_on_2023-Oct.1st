#include <bits/stdc++.h>
using namespace std;
vector <int> link[1000010];
int n, m;
const int mod = 100003;

struct stu {
	int dep, cnt;
} vis[1000010];

void dfs(int x, int dep) {
	if (vis[x].dep < dep) {
		return;
	}
	if (vis[x].dep == dep) {
		vis[x].cnt++;
		vis[x].cnt %= mod;
	} else {
		vis[x].dep = dep;
		vis[x].cnt = 1;
	}
	for (int i = 0; i < link[x].size(); i++) {
		dfs(link[x][i], dep + 1);
	}
	return;
}

int main() {
	//freopen("P1144_3.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1, tmpa, tmpb; i <= m; i++) {
		cin >> tmpa >> tmpb;
		link[tmpa].push_back(tmpb);
		link[tmpb].push_back(tmpa);
	}
	for (int i = 1; i <= n; i++) {
		vis[i].dep = 1000010;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		cout << vis[i].cnt << endl;
	}
	return 0;
}

