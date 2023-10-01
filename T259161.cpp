#include <iostream>
using namespace std;
int n, k, a[100010], i, j;

int main() {
	cin >> n >> k;
	a[0] = a[1] = 1;
	for (i = 2; i <= n; i++) {
		for (j = max(i - k, 0); j < i; j++) {
			a[i] += a[j];
			a[i] %= 100003;
		}
	}
	cout << a[n] << endl;
	return 0;
}