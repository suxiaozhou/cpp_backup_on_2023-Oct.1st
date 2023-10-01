#include <iostream>
using namespace std;
int n, i, j, p, list[10005];

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> p;
		list[p]++;
	}
	for (i = 10000; i >= 0; i--) {
		for (j = 0; j < list[i]; j++)
			cout << i << " ";
	}
	return 0;
}