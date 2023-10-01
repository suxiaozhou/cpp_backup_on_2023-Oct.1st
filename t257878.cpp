#include <iostream>
using namespace std;
int n, m, i, j, y, t[105], T = 0, l = 0, p;

struct a {
	int key, code;
};
struct a list[5010];

int main() {
	cin >> n >> m;
	m *= 1.5;
	for (i = 0; i < n; i++) {
		cin >> list[i].code >> list[i].key;
		t[list[i].key]++;
	}
	for (i = 100; i >= 0; i--) {
		T += t[i];
		if (T > m) {
			m = i;
			break;
		}
	}
	cout << m << " " << T << endl;
	struct a wl[m];
	for (i = 0; i < n; i++) {
		if (list[i].key >= m) {
			wl[l] = list[i];
			l++;
		}
	}
	for (j = 100; j >= m; j--) {
		int li[t[j]], q = 0;
		for (i = 0; i < t[j]; i++) {
			for (y = q; y < m; y++) {
				if (list[y].key == j) {
					li[i] = list[y].code;
					break;
				}
				q++;
			}
		}
		for (i = 0; i < t[j]; i++) {
			for (y = i + 1; y < t[j]; y++) {
				if (li[i] > li[y]) {
					p = li[i];
					li[i] = li[y];
					li[y] = p;
				}
			}
		}
		for (i = 0; i < t[j]; i++) {
			cout << li[i] << " " << j << endl;
		}
	}
	return 0;
}