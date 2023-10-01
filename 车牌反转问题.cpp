#include <bits/stdc++.h>
using namespace std;
int l[10], test[10];

int e[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6}, ans = 0;
void solve(int x) {
	if (x == 6) {
		for (int i = 1; i < 6; i++) {
			test[6 - i] = e[l[i]];
		}
		bool flag = true;
		for (int i = 1; i < 6; i++) {
			if (test[i] != l[i]) {
				flag = false;
			}
		}
		if (flag) {
			for (int i = 1; i < 6; i++) {
				cout << l[i] << " ";
			}
			cout << endl;
			ans++;
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (e[i] == -1) {
			continue;
		}
		l[x] = i;
		solve(x + 1);
	}
}
int main() {
	solve(1);
	cout << ans << endl;
	return 0;
}

