#include <iostream>
using namespace std;
int a, b;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

int main() {
	cin >> a >> b;
	if (b > a) {
		swap(a, b);
	}
	cout << gcd(a, b) << endl;
	return 0;
}