#include <bits/stdc++.h>
using namespace std;
int n, m = 0, pan[15];

void dfs(int pos) {
	if (pos == n + 1) {
		m++;
		if (m <= 3) {
			for (int i = 1; i <= n; i++) {
				cout << pan[i];
				if (i != n) {
					cout << " ";
				}
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++) { //зјБъ=(pos,i)
		bool flag = true;
		for (int j = 1; j < pos; j++) {
			if (pan[j] == i || (pan[pos - j] == i - j && i - j > 0) || (pan[pos - j] == i + j && i + j <= n)) {
				flag = false;
			}
		}
		if (flag) {
			pan[pos] = i;
			dfs(pos + 1);
			pan[pos] = 0;
		}
	}
	return;
}

int main() {
	//freopen("P1219.in", "r", stdin);
	cin >> n;
	dfs(1);
	cout << m << endl;
	return 0;
}