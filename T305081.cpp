#include <iostream>
#include <cmath>
using namespace std;
int l, l1 = 0, s, flag, i, j, ans;

int main() {
	cin >> l;
	for (i = 2;; i++) {
		s = sqrt(i);
		flag = 1;
		for (j = 2; j <= s; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			continue;   //并非质数
		}
		if (i + l1 > l) {
			break;   //超了
		}
		cout << i << endl;
		ans++;
		l1 += i;
	}
	cout << ans << endl;
	return 0;
}