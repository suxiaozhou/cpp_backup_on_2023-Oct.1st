#include <iostream>
using namespace std;
int n, m, l, i, j, list[5010], tmp, type, x, y;

int main() {
	cin >> n >> m;
	l = n;
	for (i = 0; i < n; i++) {
		cin >> list[i];
	}
	for (i = 0; i < m; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			tmp = y;
			for (j = x - 1; j <= l; j++) {
				swap(tmp, list[j]);
				//cout << "***" << tmp << list[x] << endl;
			}
			l++;
		} else if (type == 2) {
			cin >> x;
			for (j = x - 1; j < l; j++) {
				list[x - 1] = list[x];
			}
			l--;
		}
		for (j = 0; j < l; j++) {
			cout << list[j] << " ";
		}
		cout << endl;
	}
	return 0;
}