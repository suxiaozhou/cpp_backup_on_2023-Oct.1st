#include <bits/stdc++.h>
using namespace std;
stack <unsigned long long> l;
string cmd;
int T, i, j, n;
unsigned long long x;

int main() {
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> n;
		for (j = 0; j < n; j++) {
			cin >> cmd;
			if (cmd == "push") {
				cin >> x;
				l.push(x);
			} else if (cmd == "pop") {
				if (l.empty()) {
					cout << "Empty" << endl;
				} else {
					l.pop();
				}
			} else if (cmd == "query") {
				if (l.empty()) {
					cout << "Anguei!" << endl;
				} else {
					cout << l.top() << endl;
				}
			} else if (cmd == "size") {
				cout << l.size() << endl;
			}
		}
		while (!l.empty()) {
			l.pop();
		}
	}
	return 0;
}