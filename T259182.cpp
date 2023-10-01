#include <iostream>
using namespace std;
int n, i, j, k;
long long ans = -1, l[1010][1010];
bool rongshen = false;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> l[i][j];
			if (l[i][j] == 0) {
				rongshen = true;
			}
		}
	}
	if (!rongshen) {
		cout << "Bad Game!" << endl;
		return 0;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (l[i][j] == 0) {
				long long p = 0;
				for (k = 0; k < n; k++) {
					p += l[i][k] + l[k][j];
				}
				if (p > ans) {
					ans = p;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}