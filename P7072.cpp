#include <bits/stdc++.h>
using namespace std;
int n, w, li[610], j, tmp, sum;

int main() {
	cin >> n >> w;
	for (int i = 1; i <= n; i++, sum = 0) {
		int g = max(1, i * w / 100);
		cin >> tmp;
		li[tmp]++;
		for (j = 600; j >= 0; j--) {
			sum += li[j];
			if (sum >= g) {
				cout << j << " ";
				break;
			}
		}
	}
	cout << endl;
	return 0;
}

