#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[100010];
vector<int>link[100010];

void dfs(int x) {
	if (vis[x]) {
		return;
	}
	cout << x << " ";
	vis[x] = 1;
	sort(link[x].begin(), link[x].end());
	for (int i = 0; i < link[x].size(); i++) {
		dfs(link[x][i]);
	}
	return;
}

void bfs() {
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (vis[x]) {
			continue;
		}
		vis[x] = 1;
		cout << x << " ";
		for (int i = 0; i < link[x].size(); i++) {
			q.push(link[x][i]);
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1, tmpa, tmpb; i <= m; i++) {
		cin >> tmpa >> tmpb;
		link[tmpa].push_back(tmpb);
	}
	dfs(1);
	cout << endl;
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	bfs();
	cout << endl;
	return 0;
}

