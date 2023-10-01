#include <bits/stdc++.h>
using namespace std;

/*
    思 路：
8^4=4096=16^3
所以可以将八进制数分成若干个四段，不影响结果
类似的还有：
2^4=16^1
可以将二进制数分成若干个四段，也不影响结果
测试：
oct:1234565422552265111555        1421270164356043242400     110640041200522201545
hex:A72E B12B 52D4 936D           C457 0747 708D 4500        1234 0214 0549 0365
*/
char inttochar(int in) {
	if (in >= 0 && in <= 9) {
		return in + '0';
	}
	return in + 'a' - 10;
}
string S, s, out = "", ans;
int i, j, n = 0, a[7], t = 0;

int main() {
	cin >> s;
	for (j = s.length(); j >= 0; j -= 4) {
		ans = "";
		S = s.substr(max(0, j - 4), min(4, j - 0));
		for (i = S.length() - 1; i >= 0; i--) {
			n += (S[i] - '0') * pow(8, S.length() - 1 - i);
		}
		//
		t = 0;
		while (n) {
			a[t] = n % 16;
			n = n / 16;
			t++;
		}
		if (j - 4 >= 0) {
			for (i = t; i < 3; ++i) {
				ans = "0" + ans;
			}
		}
		for (i = t - 1; i >= 0; i--) {
			ans += inttochar(a[i]);
		}
		out = ans + out;
	}
	cout << out << endl;
	return 0;
}