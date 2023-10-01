#include <bits/stdc++.h>
using namespace std;
int s[2010][2010], N, M;
long long f[2010][2010], ans = 23333333333;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> s[i][j];
		}
	}
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= M; i++) {
			long long tmp = 23333333333;
			if (i > 1) {
				tmp = f[i - 1][j - 1];
			}
			f[i][j] = min(f[i][j - 1], i == 1 ? f[M][j - 1] : tmp) + s[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		ans = min(ans, f[i][N]);
	}
	cout << ans;
	return 0;
}

