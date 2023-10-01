#include <iostream>
using namespace std;
long long c[50];

int main() {
	int n;
	cin >> n;
	c[1] = 1;
	c[2] = 1;
	for (int i = 3; i <= n; i++) {
		c[i] = c[i - 1] + c[i - 2];
	}
	cout << c[n] << ".00" << endl;
	return 0;
}