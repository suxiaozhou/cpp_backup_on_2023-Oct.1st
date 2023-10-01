#include <bits/stdc++.h>
using namespace std;
queue <int> l;
int n, m, i, j;

int main() {
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		l.push(i + 1);
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++) {
			l.push(l.front());
			l.pop();
		}
		cout << l.front() << " ";
		l.pop();
	}
	return 0;
}