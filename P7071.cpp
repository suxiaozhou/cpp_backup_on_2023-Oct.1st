#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	cin >> n;
	queue <int> q;
	for (int i = 30; i > 0; i--) {
		if (n >= pow(2, i)) {
			n -= pow(2, i);
			q.push(i);
		}
	}
	if (n != 0) {
		cout << -1 << endl;
		return 0;
	}
	cout.setf(ios::fixed);
	cout.precision(0);
	while (!q.empty()) {
		cout << pow(2, q.front()) << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}
