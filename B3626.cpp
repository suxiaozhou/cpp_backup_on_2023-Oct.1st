#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[1000010];

struct Pos {
	int n, costn;
	Pos(int an, int acostn) {
		n = an, costn = acostn;
	}
};

void bfs() {
	queue <Pos> q;
	q.push(Pos(1, 0));
	while (!q.empty()) {
		Pos now = q.front();
		q.pop();
		if (now.n < 1 || now.n > n || vis[now.n]) {
			continue;
		}
		vis[now.n] = 1;
		if (now.n == n) {
			cout << now.costn << endl;
			return;
		}
		q.push(Pos(now.n + 1, now.costn + 1));
		q.push(Pos(now.n - 1, now.costn + 1));
		q.push(Pos(now.n * 2, now.costn + 1));
	}
}

int main() {
	cin >> n;
	bfs();
	return 0;
}

