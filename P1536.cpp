#include <bits/stdc++.h>
using namespace std;
int nextl[1010], stopflag = 0, n;

int zhuigensuyuan(int x, int con) { //查清他祖宗
	if (con >= n) {
		return 0;
	}
	if (nextl[x] != x) {
		return zhuigensuyuan(nextl[x], con + 1);
	}
	return x;
}

void u() {
	int m, i, u = 0, p, l, r, j;
	cin >> n;
	if (n == 0) {
		stopflag = 1;
		return;
	}
	for (i = 1; i <= n; i++) {
		nextl[i] = i;
	}
	cin >> m;
	if (m == 0) {
		cout << n - 1 << endl;
		return;
	}
	for (i = 0; i < m; i++) {
		cin >> l >> r;
		nextl[zhuigensuyuan(l, 0)] = zhuigensuyuan(r, 0);
	}
	for (i = 1; i <= n; i++) {
		if (nextl[i] == i) {
			u++;//康康一共有几个祖宗，就知道一共有几个家族了。
		}
	}
	cout << u - 1 << endl;
	return;
}

int main() {
	//freopen("P1536_1.in", "r", stdin);
	while (!stopflag) {
		u();
	}
	return 0;
}