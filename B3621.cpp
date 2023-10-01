#include <bits/stdc++.h>
using namespace std;
int n, k, li[10];

void dfs(int c) {
	if (n == c - 1) {
		for (int i = 1; i <= n; i++) {
			cout << li[i];
			if (i != n) {
				cout << " ";
			}
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= k; i++) {
		li[c] = i;
		dfs(c + 1);
	}
	return;
}

int main() {
	cin >> n >> k;
	dfs(1);
	return 0;
}