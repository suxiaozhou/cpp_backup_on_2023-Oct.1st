#include <bits/stdc++.h>
using namespace std;
int n, li[20];

void dfs(int c) {
	if (n == c - 1) {
		for (int i = 1; i <= n; i++) {
			if (li[i]) {
				cout << "Y";
			} else {
				cout << "N";
			}
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < 2; i++) {
		li[c] = i;
		dfs(c + 1);
	}
	return;
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}