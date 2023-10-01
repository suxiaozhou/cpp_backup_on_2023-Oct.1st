#include <iostream>
#include <algorithm>
using namespace std;
int i, n, k, list[10010], tmp = -1;

int main() {
	cin >> n >> k;
	for (i = 0; i < n; i++) {
		cin >> list[i];
	}
	sort(list, list + n);
	for (i = 0; i < n; i++) {
		if (list[i] != tmp) {
			k--;
			tmp = list[i];
		}
		if (k == 0) {
			cout << tmp << endl;
			return 0;
		}
	}
	cout << "NO RESULT" << endl;
	return 0;
}