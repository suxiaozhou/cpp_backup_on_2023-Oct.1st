#include <bits/stdc++.h>
using namespace std;
map <int, int> m;
int pos[200010], posl = 1, n, z, tmp;
unsigned long long ans = 0;

int main() {
	cin >> n >> z;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		pos[posl] = tmp;
		if (m.find(tmp) == m.end()) {
			m[tmp] = 0;
		}
		m[tmp]++;
		posl++;
	}
	for (int i = 1; i < posl; i++) {
		if (m.find(pos[i] + z) != m.end()) {
			ans += m[pos[i] + z];
		}
	}
	cout << ans << endl;
	return 0;
}

