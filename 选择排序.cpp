#include <iostream>
using namespace std;
long long list[105], p;
int n, ans = 0, i, j;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i];
	}
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (list[i] > list[j]) {
				ans++;
				p = list[i];
				list[i] = list[j];
				list[j] = p;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << list[i] << " ";
	}
	cout << endl << ans << endl;
	return 0;
}