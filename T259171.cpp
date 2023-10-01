#include <bits/stdc++.h>
using namespace std;
int l[1010], a, b, i, ans = 0;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> a >> b;
	for (i = 0; i < a; i++) {
		cin >> l[i];
	}
	sort(l, l + a, cmp);
	for (i = 0; i < b; i++) {
		ans += l[i];
	}
	cout << ans << endl;
	return 0;
}
