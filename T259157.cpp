#include <stdio.h>
using namespace std;
int T, n, m, a[4010][4010], i, j;

int main() {
	scanf("%d", &T);
	a[0][0] = 1;
	for (i = 1; i <= 4000; i++) {
		a[i][0] = 1;
		for (j = 1; j < i; j++) {
			a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % 998244353;
		}
	}
	for (i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", a[n + 1][m]);
	}
	return 0;
}