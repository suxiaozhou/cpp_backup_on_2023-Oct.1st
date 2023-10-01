#include <bits/stdc++.h>
using namespace std;
int n, k, li[100010];

bool is(int m) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += li[i] / m;
	}
	return sum >= k;
}

void s(int l, int r) {
	if (r == l + 1) {
		cout << l << endl;
		return;
	}
	int m = (l + r) / 2;
	if (is(m)) {
		s(m, r);
	} else {
		s(l, m);
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> li[i];
	}
	s(0, 1000000010);
	return 0;
}

