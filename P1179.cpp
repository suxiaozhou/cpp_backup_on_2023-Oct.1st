#include <bits/stdc++.h>
using namespace std;
int L, R, i, j, ans = 0;
string p;

int main() {
	cin >> L >> R;
	for (i = L; i <= R; i++) {
		p = to_string(i);
		for (j = 0; j < p.length(); j++) {
			if (p[j] == '2') {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
