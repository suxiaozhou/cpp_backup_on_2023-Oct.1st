#include <bits/stdc++.h>
using namespace std;
int n, s, a1, b, l = 0, h, i;

struct g {
	int x, y;
} a[5010];

bool cmp(g x, g y) {
	if (x.y == -1) {
		return false;
	}
	if (y.y == -1) {
		return true;
	}
	return y.y > x.y;
}

int main() {
	cin >> n >> s >> a1 >> b;
	h = a1 + b;
	for (i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		if (a[i].x > h) {
			a[i].y = -1;
			l++;
		}
	}
	sort(a, a + n, cmp);
	n -= l;
	for (i = 0; i < n; i++) {
		if (s - a[i].y < 0) {
			break;
		}
		s -= a[i].y;
	}
	cout << i << endl;
	return 0;
}