#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
bool QreenPos[maxn][maxn], act[maxn][maxn], printmode = 0;
int ans = 0;

void update_act_qreen(int n, int x, int y) {
	int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
	for (int i = 1; i <= n; i++) { //距离?
		for (int j = 0; j < 8; j++) { //方向?
			int tmpx = x + i * dx[j], tmpy = y + i * dy[j];
			if (tmpx > 0 && tmpx <= n && tmpy > 0 && tmpy <= n) { //不会越界
				act[tmpx][tmpy] = 1;
			}
		}
	}
	return;
}

void print(int n) {
	if (printmode) {
		cout << "---------" << ans << "-----------" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << QreenPos[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return;
}

void dfs(int n, int level) {
	if (level > n) { //发现答案
		ans++;
		print(n);
		return;
	}
	//test
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << act[i][j] << " ";
		}
		cout << endl;
	}
	//test
	*/
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		if (act[i][level] == 0) { //可以填皇后
			//save
			bool tmp[maxn][maxn], flag = 1;
			for (int k = 1; k <= n; k++) {
				for (int j = 1; j <= n; j++) {
					tmp[k][j] = act[k][j];
				}
			}
			//update
			update_act_qreen(n, i, level);
			QreenPos[i][level] = 1;
			//continue
			dfs(n, level + 1);
			//back
			QreenPos[i][level] = 0;
			for (int k = 1; k <= n; k++) {
				for (int j = 1; j <= n; j++) {
					act[k][j] = tmp[k][j];
				}
			}
		}
	}
	return;
}

int main() {
	if (0) {
		freopen("N皇后.out", "w", stdout);
	}
	int n;
	cin >> n;
	dfs(n, 1);
	cout << "共有" << ans << "种可能." << endl;
	return 0;
}

