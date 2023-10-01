#include <bits/stdc++.h>
using namespace std;
int n, k, use[20], li[20];

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
		if (!use[i]) {
			li[c] = i;
			use[i] = 1;
			dfs(c + 1);
			use[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> n >> k;
	int z = k;
	k = n;
	n = z;
	dfs(1);
	return 0;
}