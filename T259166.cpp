#include <iostream>
using namespace std;
int n, m, a[10010], b[10010], flag[10010], ansn = -1, l = 0, flagn = 0, i;

void dfs(int k) {
	if (k > n) {
		//
		for (i = 1; i <= n; i++) {
			cout << b[i] << " ";
		}
		cout << endl;
		//
		l++;
		flagn = 0;
		for (i = 1; i <= n; i++) {
			if (a[i] != b[i]) {
				flagn = 1;
			}
		}
		if (!flagn) {
			ansn = l + m;
		}
		if (l == ansn) {
			for (i = 1; i <= n; i++) {
				cout << b[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (i = 1; i <= n; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			b[k] = i;
			dfs(k + 1);
			flag[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout <<  l << " " << ansn << endl;
	return 0;
}