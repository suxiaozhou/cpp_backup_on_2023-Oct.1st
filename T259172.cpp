#include <bits/stdc++.h>
using namespace std;
int N, T, i;
double ans;

struct coin {
	int m, v;
} a[110];

bool cmp(coin x, coin y) {
	return x.v * y.m > y.v * x.m;
}

int main() {
	cin >> N >> T;
	for (i = 0; i < N; i++) {
		cin >> a[i].m >> a[i].v;
	}
	sort(a, a + N, cmp);
	for (i = 0; i < N; i++) {
		if (T < a[i].m) {
			ans += 1.0 * T / a[i].m * a[i].v;
			break;
		}
		ans += a[i].v;
		T -= a[i].m;
	}
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}