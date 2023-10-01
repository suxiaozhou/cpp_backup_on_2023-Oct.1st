#include <bits/stdc++.h>
using namespace std;

char inttochar(int in) {
	if (in < 10) {
		return in + '0';
	}
	return in + 'A' - 10;
}

int chartoint(char in) {
	if (in >= '0' && in <= '9') {
		return in - '0';
	}
	return in - 'A' + 10;
}
string S;
int x, k, ans = 0, a[40], t = 0, i;

int main() {
	cin >> x >> S >> k;
	for (i = S.length() - 1; i >= 0; i--) {
		ans += chartoint(S[i]) * pow(x, S.length() - 1 - i);
	}
	//
	while (ans) {
		a[t] = ans % k;
		ans = ans / k;
		t++;
	}
	for (i = t - 1; i >= 0; i--) {
		cout << inttochar(a[i]);
	}
	cout << endl;
	return 0;
}