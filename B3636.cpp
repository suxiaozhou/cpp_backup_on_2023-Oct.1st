#include <bits/stdc++.h>
using namespace std;
int n;
long long li[1000010];

int main() {
	cin >> n;
	li[0] = 0;
	for (int i = 1; i <= n; i++) {
		long long tmp1 = 1000000000000;
		if (i % 2 == 0) {
			tmp1 = li[i / 2] + 1;
		}
		li[i] = min(li[i - 1] + 1, tmp1);
	}
	cout << li[n] - 1 << endl;
	return 0;
}

