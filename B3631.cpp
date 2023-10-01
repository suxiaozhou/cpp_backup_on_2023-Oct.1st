#include <bits/stdc++.h>
using namespace std;
int q, x, y, nxt[1000010], cmd, tmp;

int main() {
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> x >> y;
			tmp = nxt[x];
			nxt[x] = y;
			nxt[y] = tmp;
		} else if (cmd == 2) {
			cin >> x;
			cout << nxt[x] << endl;
		} else {
			cin >> x;
			nxt[x] = nxt[nxt[x]];
		}
	}
	return 0;
}

