#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
int flag[maxn], b[maxn], i, n;

int dfs(int g) {
	if (g > n) {
		for (i = 1; i <= n; i++) {
			printf("%5d", b[i]);
		}
		printf("\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			flag[i] = 1;
			b[g] = i;
			dfs(g + 1); //继续甩
			flag[i] = 0; //用完放回去
		}
	}
}

int main() {
	cin >> n;
	dfs(1);
	return 0;
}