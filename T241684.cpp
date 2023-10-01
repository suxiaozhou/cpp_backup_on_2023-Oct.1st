#include <bits/stdc++.h>
using namespace std;
int nxt[110], n, m, last;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			nxt[i] = i + 1;
		} else {
			nxt[i] = 1;
		}
	}
	m--;
	for (int now = 1;; now = last) {
		for (int i = 1; i <= m; i++) {
			if (m == i) {
				last = now;
			}
			now = nxt[now];
		}
		cout << now;
		if (nxt[now] != now) {
			cout << " ";
		}
		nxt[last] = nxt[now];
		if (nxt[now] == now) {
			break;
		}
	}
	return 0;
}

