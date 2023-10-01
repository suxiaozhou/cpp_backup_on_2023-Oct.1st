#include <bits/stdc++.h>
using namespace std;
int N, A, B, li[210];
bool vis[210];

struct Pos {
	long long p, cost;
	Pos(long long ap, long long acost) {
		p = ap, cost = acost;
	}
};

void bfs() {
	queue <Pos>q;
	q.push(Pos(A, 0));
	while (!q.empty()) {
		int now = q.front().p, cost = q.front().cost;
		q.pop();
		if (now < 1 || now > N || vis[now]) {
			continue;
		}
		vis[now] = 1;
		if (now == B) {
			cout << cost << endl;
			return;
		}
		q.push(Pos(now + li[now], cost + 1));
		q.push(Pos(now - li[now], cost + 1));
	}
	cout << -1 << endl;
	return;
}

int main() {
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++) {
		cin >> li[i];
	}
	bfs();
	return 0;
}

