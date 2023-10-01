#include <iostream>
#include <cmath>
using namespace std;
double i, n, c;
int T;

double s(double a, double b, double j, int T) {
	for (i = a; i <= b; i += j) {
		if (i * i > T) {
			break;
		}
	}
	return i - j;
}

int main() {
	cout << "保留位数：" << "需计算值：" << "估算值:" << endl;
	cin >> n >> T >> c;
	cout << s(c - 1.0, c + 1.0, 1 / pow(10, n), T) << endl;
	return 0;
}