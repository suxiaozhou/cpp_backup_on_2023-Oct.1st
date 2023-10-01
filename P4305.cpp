#include <bits/stdc++.h>
using namespace std;
map <int, bool> m;
int l[50010], t, n;

int main() {
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> l[j];
		}
		for (int j = 1; j <= n; j++) {
			if (!m[l[j]]) {
				cout << l[j] << " ";
				m[l[j]] = true;
			}
		}
		m.clear();
		cout << endl;
	}
	return 0;
}

