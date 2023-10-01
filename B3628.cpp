#include <bits/stdc++.h>
using namespace std;

int n, li[100010];

bool can(int m) {
	for (int i = 1; i <= n; i++) {
		m += li[i];
		if (m <= 0) {
			return false;
		}
	}
	return true;
}

void s(int l, int r) {
	if (r - l <= 1) {
		cout << r << endl;
		return;
	}
	int m = (l + r) / 2;
	if (can(m)) {
		s(l, m);
	} else {
		s(m, r);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> li[i];
	}
	s(1, 1000010);
	return 0;
}

