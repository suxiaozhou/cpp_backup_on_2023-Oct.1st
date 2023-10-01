#include <iostream>
using namespace std;
long long n, list[100][100];

int main() {
	cin >> n;
	list[0][0] = 1;
	for (int i = 1; i < n; i++) {
		list[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			list[i][j] = list[i - 1][j - 1] + list[i - 1][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}