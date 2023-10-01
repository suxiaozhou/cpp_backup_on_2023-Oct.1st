#include <bits/stdc++.h>
using namespace std;
long long n;

void s(int l, int r) {
	if (r - l <= 1) {
		cout << l << endl;
		return;
	}
	int m = (l + r) / 2;
	if (pow(m, 3) > n) {
		s(l, m);
	} else {
		s(m, r);
	}
}

int main() {
	cin >> n;
	s(1, 100010);
	return 0;
}

