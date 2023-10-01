#include <bits/stdc++.h>
using namespace std;
int t[110], v[110], f[110][1010], ti, m;

int main() {
	cin >> ti >> m;
	for (int i = 1; i <= m; i++) {
		cin >> t[i] >> v[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= ti; j++) {
			if (j - t[i] >= 0) {
				f[i][j] = f[i - 1][j - t[i]] + v[i];
			}
			f[i][j] = max(f[i][j], f[i - 1][j]);
		}
	}
	cout << f[m][ti] << endl;
	return 0;
}

