#include <bits/stdc++.h>
using namespace std;

int muzi[10005] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans = 0, i, n, j;
int main() {
	cin >> n;
	if (n < 5) {
		cout << 0 << endl;
		return 0;
	}
	n -= 4;
	for (i = 10; i <= 10000; i++) {
		muzi[i] = muzi[i / 10] + muzi[i % 10];
	}
	for (i = 0; i < 5000; i++) {
		for (j = 0; j < 5000; j++) {
			if (muzi[i] + muzi[j] + muzi[i + j] == n) {
				/*
				cout << i << "+" << j << "=" << i + j << endl;
				cout << muzi[i] << " " << muzi[j] << " " << muzi[i + j] << endl;
				*/
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}