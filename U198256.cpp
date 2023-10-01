#include <stdio.h>
using namespace std;
int T, n, m, ans, l[4010][4010], i, j;

int main() {
	l[0][0] = 1;
	//**
	for (i = 1; i <= 4000; i++) {
		l[i][0] = 1;
		for (j = 1; j <= i; j++) {
			l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]) % 998244353;
		}
	}
	//**
	scanf("%d", &T);
	for (i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		printf("%d\n", l[n][m]);
	}
	return 0;
}