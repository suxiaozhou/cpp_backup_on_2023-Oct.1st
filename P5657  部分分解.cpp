#include <bits/stdc++.h>
using namespace std;
unsigned long long k;
int n;
string vis[20][312010];

void solve(int deep) {
	if (deep == n + 1) {
		return;
	}
	for (int i = 1; i <= pow(2, deep - 1); i++) {
		vis[deep][i] = "0" + vis[deep - 1][i];
	}
	for (int i = pow(2, deep - 1) + 1, j = pow(2, deep); i <= pow(2, deep); i++, j--) {
		int p = (j - pow(2, deep - 1));
		vis[deep][i] = "1" + vis[deep - 1][ p];
	}
	solve(deep + 1);
	return;
}

int main() {
	cin >> n >> k;
	k++;
	solve(1);
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= pow(2, n); j++) {
			cerr << vis[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	cout << vis[n][k] << endl;
	return 0;
}

