#include <iostream>
#include <string>
using namespace std;
int a, b;

int akm(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	if (m > 0 && n == 0) {
		return akm(m - 1, 1);
	}
	if (m > 0 && n > 0) {
		return akm(m - 1, akm(m, n - 1));
	}
}

int main() {
	cin >> a >> b;
	cout << akm(a, b) << endl;
	return 0;
}