#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, key_DEC = 0, t = 0, ans[1000];
string s;

char int_to_char(int num) {
	if (num < 10) {
		return num + '0';
	}
	return num + 'A' - 10;
}

int char_to_int(char num) {
	if (num <= '9') {
		return num - '0';
	}
	return num - 'A' + 10;
}

int main() {
	cin >> n >> s >> k;
	for (i = 0; i < s.length(); i++) {
		key_DEC += char_to_int(s[i]) * pow(n, s.length() - 1 - i);
	}
	while (key_DEC) {
		ans[t] = key_DEC % k;
		key_DEC /= k;
		t++;
	}
	for (i = t - 1; i >= 0; i--) {
		cout << int_to_char(ans[i]);
	}
	cout << endl;
	return 0;
}