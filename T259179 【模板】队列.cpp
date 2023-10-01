#include <bits/stdc++.h>
using namespace std;
queue <int> l;
int n, i, cmd, x;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> x;
			l.push(x);
		} else if (cmd == 2) {
			if (l.empty()) {
				cout << "ERR_CANNOT_POP" << endl;
			} else {
				l.pop();
			}
		} else if (cmd == 3) {
			if (l.empty()) {
				cout << "ERR_CANNOT_QUERY" << endl;
			} else {
				cout << l.front() << endl;
			}
		} else if (cmd == 4) {
			cout << l.size() << endl;
		}
	}
	return 0;
}
