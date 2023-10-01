#include <bits/stdc++.h>
using namespace std;
int n = 2000, m, t, lin[2010][2010], i, j;

int main() {
	for (i = 1; i <= n; i++) {
		lin[1][i] = 1;
		lin[i][1] = 1;
		lin[0][i] = 1;
	}
	for (i = 2; i <= n; i++) {
		for (j = 2; j <= i; j++) {
			//也就是说，要嘛少盘子,多出来的盘子放空；要嘛分苹果，“甩锅”给下一层
			lin[i][j] = lin[i][j - 1] + lin[i - j][j];
		}
	}
	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> n >> m;
		if (m > n) {
			cout << lin[n][n] << endl;
		} else {
			cout << lin[n][m] << endl;
		}
	}
	return 0;
}