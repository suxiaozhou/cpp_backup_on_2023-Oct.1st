#include <iostream>
#include <algorithm>
using namespace std;

long long i, list[300010], tmp[2] = {-1, 0}, n;
int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i];
	}
	list[i] = -1;
	sort(list, list + n);
	for (i = 0; i <= n; i++) {
		if (list[i] == tmp[0]) {
			tmp[1]++;
		} else {
			if (tmp[0] != -1) {
				cout << list[i - 1] << " " << tmp[1] << endl;
			}
			tmp[1] = 1;
			tmp[0] = list[i];
		}
	}
	return 0;
}