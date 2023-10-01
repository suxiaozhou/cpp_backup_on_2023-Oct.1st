#include <iostream>
using namespace std;

int main() {
	int m, k;
	cin >> m;
	for (int k = m - 1; k > 1; k--) { //列举长度
		if (2 * m % k == 0) { //确保min+max为整数
			if ((2 * m / k + 1 - k) % 2 == 0) { //确保min为整数
				int min = (2 * m / k - k + 1) / 2;
				if (min >= 0) {
					cout << min << " " << min + k - 1 << endl;
				}
			}
		}
	}
	return 0;
}