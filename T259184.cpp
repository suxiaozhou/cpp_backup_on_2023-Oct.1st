#include <bits/stdc++.h>

using namespace std;
int n, i;
double ans, p, l[300010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l, l + n, cmp);
	cout << endl;
	long long m = 0;
	for (i = 0; i < n; i++) {
		p = (l[i] + m) * (l[i] + m) / (i + 1);
		if (p > ans) {
			ans = p;
			m += l[i];
		} else {
			break;
		}
	}
	cout << fixed << setprecision(8) << ans << endl;
	return 0;
}