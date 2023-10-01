#include <iostream>
using namespace std;

char inttochar(int in) {
	if (in < 10) {
		return in + '0';
	}
	return in + 'A' - 10;
}
int n, k, a[45], i, t = 0;

int main() {
	cin >> n >> k;
	while (n) {
		a[t] = n % k;
		n = n / k;
		t++;
	}
	for (i = t - 1; i >= 0; i--) {
		cout << inttochar(a[i]);
	}
	cout << endl;
	return 0;
}