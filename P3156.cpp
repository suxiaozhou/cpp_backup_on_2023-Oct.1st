#include <bits/stdc++.h>
using namespace std;
int stu[2000010], n, m, i, tmp;

int main() {
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> stu[i];
	}
	for (i = 0; i < m; i++) {
		cin >> tmp;
		cout << stu[tmp - 1] << endl;
	}
	return 0;
}

