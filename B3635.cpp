#include <bits/stdc++.h>
using namespace std;
int n;
long long li[1000010];

int main() {
	cin >> n;
	li[0] = 0;
	li[1] = 1;
	for (int i = 2; i <= n; i++) {
		long long tmp = 1000000000000, tmp1 = 1000000000000;
		if (i - 5 >= 0) {
			tmp = li[i - 5] + 1;
		}
		if (i - 11 >= 0) {
			tmp1 = li[i - 11] + 1;
		}
		li[i] = min(li[i - 1] + 1, min(tmp, tmp1));
		//cout << li[i] << endl;
	}
	cout << li[n] << endl;
	return 0;
}

