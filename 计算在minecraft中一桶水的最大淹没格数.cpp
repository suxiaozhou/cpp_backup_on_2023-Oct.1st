#include <bits/stdc++.h>
using namespace std;

int main() {
	long long ans = 0;
	for (int n = 1; n <= 384; n++) {
		long long sum = 0;
		for (int m = 1; m <= 6 * n; m++) {
			sum += m;
		}
		sum *= 4;
		sum += 1;
		sum *= (384 - n + 1);
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}

