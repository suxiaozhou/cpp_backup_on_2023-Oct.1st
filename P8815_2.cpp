#include <bits/stdc++.h>
using namespace std;
int orl = 0, andl = 0;
string str;

bool solve(string s) {
	//cerr << s << endl;
	bool ans = 0, val = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0' || s[i] == '1') {
			if (val) {
				val = 0;
			} else {
				ans = s[i] - '0';
			}
			//cerr << "a2" << endl;
		} else if (s[i] == '|') {
			if (ans) {
				orl++;
				ans = 1;
				val = 1;
			}
			//cerr << "b" << endl;
		} else if (s[i] == '&') {
			if (!ans) {
				andl++;
				ans = 0;
				val = 1;
			}
			//cerr << "c" << endl;
		} else if (s[i] == '(') {
			int tmp = i, tmp1 = 0;
			while (1) {
				if (s[i] == '(') {
					tmp1++;
				}
				if (s[i] == ')') {
					tmp1--;
					if (tmp1 == 0) {
						break;
					}
				}
				i++;
			}
			if (val) {
				val = 0;
				continue;
			}
			//cerr << "d2" << endl;
			ans = solve(s.substr(tmp + 1, i - tmp - 1));
		}
	}
	return ans;
}

int main() {
	cin >> str;
	cout << solve(str) << endl;
	cout << andl << " " << orl << endl;
	return 0;
}

