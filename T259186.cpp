#include <bits/stdc++.h>
using namespace std;
int ans = 0, stoptime = -1, i, n;

struct tim {
	int start, stop;
} tl[1000010];

bool cmp(tim a, tim b) {
	return a.stop < b.stop;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> tl[i].start >> tl[i].stop;
	}
	sort(tl, tl + n, cmp);
	for (i = 0; i < n; i++) {
		if (tl[i].start < stoptime) {
			continue;
		}
		stoptime = tl[i].stop;
		ans++;
	}
	cout << ans << endl;
	return 0;
}