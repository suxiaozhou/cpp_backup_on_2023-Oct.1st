#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int chartoint(char in) {
	if (in >= '0' && in <= '9') {
		return in - '0';
	}
	return in - 'A' + 10;
}
string S;
int x, ans = 0, i;

int main() {
	cin >> x >> S;
	for (i = S.length() - 1; i >= 0; i--) {
		ans += chartoint(S[i]) * pow(x, S.length() - 1 - i);
	}
	cout << ans << endl;
	return 0;
}