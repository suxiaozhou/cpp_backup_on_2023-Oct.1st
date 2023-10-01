#include <bits/stdc++.h>
using namespace std;
int li[110][110], vis[110][110], n, m, i, j, flag;

struct Pos {
	int x, y;
	Pos(int ax, int ay) {
		x = ax, y = ay;
	}
};

void bfs() {
	queue<Pos> q;
	q.push(Pos(1, 1));
	while (!q.empty()) {
		Pos npos = q.front();
		q.pop();
		if (li[npos.x][npos.y] || npos.x < 1 || npos.x > n || npos.y < 1 || npos.y > m || vis[npos.x][npos.y])
			continue;
		vis[npos.x][npos.y] = 1;
		if (npos.x == n && npos.y == m) {
			flag = 1;
			return;
		}
		q.push(Pos(npos.x + 1, npos.y));
		q.push(Pos(npos.x - 1, npos.y));
		q.push(Pos(npos.x, npos.y + 1));
		q.push(Pos(npos.x, npos.y - 1));
	}
	return;
}

int main() {
	char ch;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> ch;
			if (ch == '#') {
				li[i][j] = 1;
			}
		}
	}
	bfs();
	if (flag) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
