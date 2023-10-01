#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, l = 0;

struct plan {
	int q, w, z;
};
struct plan li[100000];

bool cmp(struct plan a, struct plan b) {
	int h1 = min(a.w, a.z), h2 = min(b.w, b.z);
	if (min(a.q, h1) != min(b.q, h2)) {
		return min(a.q, h1) > min(b.q, h2);
	}
	return a.q + a.w + a.z > b.q + b.w + b.z;
}

int main() {
	cin >> n;
	for (i = 0; 7 * i <= n; i++) {
		for (j = 0; 4 * j <= n; j++) {
			for (k = 0; 3 * k <= n; k++) {
				if (7 * i + 4 * j + 3 * k == n) {
					li[l].q = i;
					li[l].w = j;
					li[l].z = k;
					l++;
				}
			}
		}
	}
	if (l == 0) {
		cout << -1 << endl;
		return 0;
	}
	sort(li, li + l, cmp);
	cout << li[0].q << " " << li[0].w << " " << li[0].z << endl;
	return 0;
}