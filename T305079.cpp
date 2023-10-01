#include <iostream>
#include <algorithm>
using namespace std;
int n, li[101], i, j, k, ans = 0;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> li[i];
	}
	sort(li, li + n);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (k = j + 1; k < n; k++) {
				if (li[i] + li[j] == li[k])
					ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}