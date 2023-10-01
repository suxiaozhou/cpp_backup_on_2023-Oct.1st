/*#include <bits/stdc++.h>
using namespace std;
int n, m, i, p, famv[1010], ans = -1;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> famv[i];
	}
	sort(famv, famv + m, cmp);
	for (i = 0; i < m; i++) {
		p = min((i + 1), n) * famv[i];
		if (p > ans) {
			ans = p;
		} else {
			break;
		}
	}
	cout << famv[i] << " " << ans << endl;
	return 0;
}
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p[10000], k, ans[2] = {0, 0}, i;
int main() {
	cin >> n >> m;
	k = m + 1;
	for (i = 0; i < m; i++) {
		cin >> p[i];
	}
	sort(p, p + m);
	for (i = 0; i < m; i++) {
		k--;
		if (k * p[i] > ans[0]) {
			ans[0] = k * p[i];
			ans[1] = p[i];
		}
	}
	cout << ans[1] << " " << ans[0] << endl;
	return 0;
}