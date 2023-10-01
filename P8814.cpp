#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k, n, d, e;

int main() {
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> n >> d >> e;
		ll b = n - e * d + 2;
		ll the = b * b - 4 * n;
		ll p = (b - sqrt(the)) / 2;
		if (sqrt(the)*sqrt(the) != the || e * d != (p - 1) * (n / p - 1) + 1) { //
			cout << "NO" << endl;
		} else {
			cout << p << " " << n / p << endl;
		}
	}
	return 0;
}
