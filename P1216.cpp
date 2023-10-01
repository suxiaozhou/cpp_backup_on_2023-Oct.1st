#include <bits/stdc++.h>
using namespace std;
int n, li[1010][1010], ans[1010][1010], answ = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> li[i][j];
		}
	}
	ans[1][1] = li[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1, tmp = 0, tmp1 = 0; j <= i; j++) {
			if (i - 1 > 0) {
				tmp = ans[i - 1][j] + li[i][j];
				if (j - 1 > 0) {
					tmp1 = ans[i - 1][j - 1] + li[i][j];
				}
			}
			ans[i][j] = max(tmp, max(ans[i][j], tmp1));
		}
	}
	for (int i = 1; i <= n; i++) {
		answ = max(answ, ans[n][i]);
	}
	cout << answ << endl;
	return 0;
}

