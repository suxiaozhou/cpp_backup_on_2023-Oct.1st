#include <bits/stdc++.h>
using namespace std;
map <int, int> m;
int n, q, tmp;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		m[tmp] = i;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> tmp;
		if (m.find(tmp) == m.end()) {
			cout << 0 << endl;
		} else {
			cout << m[tmp] << endl;
		}
	}
	return 0;
}

