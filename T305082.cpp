#include <iostream>
using namespace std;
int n, w, i, j, jiang, tmp, list[610], sum;

int main() {
	cin >> n >> w;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		list[tmp]++;
		sum = 0;
		for (j = 600; j >= 0; j--) {
			sum += list[j];
			if (sum >= max(1, (i + 1) * w / 100)) {
				cout << j << " ";
				break;
			}
		}
	}
	return 0;
}