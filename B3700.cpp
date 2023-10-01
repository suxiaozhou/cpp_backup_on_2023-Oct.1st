#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int n, i, j;
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			cout << i << " ^ " << j << " = " << fixed << setprecision(0) << pow(i, j);
			if (j != i) {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}