#include <bits/stdc++.h>
using namespace std;
vector <int> v[100010];
int n, q, cmd, tmpi, tmpj, tmpk;

int main() {
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> tmpi >> tmpj >> tmpk;
			if (tmpj > v[tmpi].size()) {
				v[tmpi].resize(tmpj + 1);
			}
			v[tmpi][tmpj] = tmpk;
		} else {
			cin >> tmpi >> tmpj;
			cout << v[tmpi][tmpj] << endl;
		}
	}
	return 0;
}

