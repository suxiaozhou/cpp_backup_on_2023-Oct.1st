#include <bits/stdc++.h>
using namespace std;
int n, fro, nxt[1000010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nxt[i];
	}
	cin >> fro;
	for (int now = fro; now != 0; now = nxt[now]) {
		cout << now;
		if (nxt[now] != 0) {
			cout << " ";
		}
	}
	return 0;
}

