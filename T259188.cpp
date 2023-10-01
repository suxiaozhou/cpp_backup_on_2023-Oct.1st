#include <iostream>
using namespace std;
int n, li[2][1010], l[1010][1010], i, j, p, ans = -1;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> p;
			if (p == 0) {
				l[i][j] = 1;
			}
			li[0][j] += p;
			li[1][i] += p;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (l[i][j] == 1) {
				p = li[0][j] + li[1][i];
				ans = max(ans, p);
			}
		}
	}
	if (ans == -1) {
		cout << "Bad Game!" << endl;
		return 0;
	}
	cout << ans << endl;
	return 0;
}