#include <iostream>
using namespace std;
int c[60][60], h[50][2], a, b, n, i, j, k, flag;

int main() {
	cin >> a >> b >> n;
	for (i = 1; i <= n; i++) {
		cin >> h[i][0] >> h[i][1];
	}
	//
	c[1][1] = 1;
	for (i = 2; i <= a; i++) {
		flag = 0;
		for (j = 1; j <= n; j++) {
			if (h[j][0] == i && h[j][1] == 1) {
				flag = 1;
			}
		}
		if (!flag) {
			c[i][1] = c[i - 1][1];
		}
	}
	for (i = 2; i <= b; i++) {
		flag = 0;
		for (j = 1; j <= n; j++) {
			if (h[j][0] == 1 && h[j][1] == i) {
				flag = 1;
			}
		}
		if (!flag) {
			c[1][i] = c[1][i - 1];
		}
	}
	for (i = 2; i <= a; i++) {
		for (j = 2; j <= b; j++) {
			flag = 0;
			for (k = 1; k <= n; k++) {
				if (h[k][0] == i && h[k][1] == j) {
					flag = 1;//Ê©¹¤ÖÐ
				}
			}
			if (!flag) {
				c[i][j] = c[i - 1][j] + c[i][j - 1];
			}
		}
	}
	//
	cout << c[a][b] << endl;
	return 0;
}