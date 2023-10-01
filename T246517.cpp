#include <bits/stdc++.h>
using namespace std;

int m[10] = {0, 1, 2, 3, 5, 10, 20}, b[1010], f[1010][1010], lenb = 0, cnt = 0, ans;

int main() {
	for (int i = 1, tmp; i <= 6; i++) {
		cin >> tmp;
		for (int j = 1; j <= tmp; j++) {
			b[++lenb] = m[i];
		}
		cnt += m[i] * tmp;
	}
	for (int i = 1; i <= lenb; i++) {//枚举使用前i个硬币
		for (int j = 1; j <= cnt; j++) {//枚举能凑出多少钱
			//如果前i-1个硬币已经能凑出j或单第i个硬币就可凑出j
			if (f[i - 1][j] == 1 || j - b[i] == 0) {
				f[i][j] = 1;
			}
			if (j - b[i] > 0 && f[i - 1][j - b[i] == 1]) {
				f[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= cnt; i++) {
		ans += f[lenb][i];
	}
	cout << "Total=" << ans << endl;
	return 0;
}

