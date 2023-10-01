#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double a, b;

double f(double x, double n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		return sqrt(n + x);
	}
	return sqrt(n + f(x, n - 1.0));
}

int main() {
	cin >> a >> b;
	cout << fixed << setprecision(2) << f(a, b) << endl;
	return 0;
}