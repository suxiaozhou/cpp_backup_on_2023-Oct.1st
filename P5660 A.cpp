#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0;

int main() {
	cin >> s;
	for (int i = 0; i < 8; i++) {
		if (s[i] == '1') {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

