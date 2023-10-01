#include <bits/stdc++.h>
using namespace std;
int li[410][410], n, m, x, y;

struct Pos {
	long long x, y, cost;
	Pos(long long ax, long long ay, long long acost) {
		x = ax, y = ay, cost = acost;
	}
};

void bfs() {
	queue <Pos> q;
	q.push(Pos(x, y, 0));
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		if (now.x < 1 || now.x > n || now.y < 1 || now.y > m || li[now.x][now.y] != -1) {
			continue;
		}
		li[now.x][now.y] = now.cost;
		q.push(Pos(now.x + 2, now.y + 1, now.cost + 1));
		q.push(Pos(now.x + 2, now.y - 1, now.cost + 1));
		q.push(Pos(now.x + 1, now.y + 2, now.cost + 1));
		q.push(Pos(now.x + 1, now.y - 2, now.cost + 1));
		q.push(Pos(now.x - 2, now.y + 1, now.cost + 1));
		q.push(Pos(now.x - 2, now.y - 1, now.cost + 1));
		q.push(Pos(now.x - 1, now.y + 2, now.cost + 1));
		q.push(Pos(now.x - 1, now.y - 2, now.cost + 1));
	}
	return;
}

int main() {
	int i, j;
	cin >> n >> m >> x >> y;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			li[i][j] = -1;
		}
	}
	bfs();
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cout << li[i][j] << "   ";
		}
		cout << endl;
	}
	return 0;
}

