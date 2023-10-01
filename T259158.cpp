#include <iostream>
using namespace std;
int n, a[1010], i, j;

int main() {
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i / 2; j++) {
			a[i] += a[j];
		}
		a[i]++;
	}
	cout << a[n] << endl;
	return 0;
}