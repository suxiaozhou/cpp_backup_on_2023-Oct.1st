#include <bits/stdc++.h>
using namespace std;
bool li[110][110], vis[110][110];
int ans, n, m;
char p;

struct Pos {
	int x, y;
	Pos(int ax, int ay) {
		x = ax;
		y = ay;
	}
};

void bfs(int x, int y) {
	int con = 0;
	queue<Pos> q;
	q.push(Pos(x, y));
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		if (now.x < 1 || now.x > n || now.y < 1 || now.y > m || vis[now.x][now.y] || !li[now.x][now.y])
			continue;
		if (!con) {
			ans++;
		}
		vis[now.x][now.y] = 1;
		q.push(Pos(now.x + 1, now.y));
		q.push(Pos(now.x - 1, now.y));
		q.push(Pos(now.x, now.y + 1));
		q.push(Pos(now.x, now.y - 1));
		con = 1;
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> p;
			if (p != '0') {
				li[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bfs(i, j);
		}
	}
	cout << ans << endl;
	return 0;
}