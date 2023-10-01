#include <bits/stdc++.h>
using namespace std;
int n;

void check(int l, int r) {
	int mid = (l + r) / 2;
	int c = mid, sum = mid;
	while (c >= 3) {
		sum += c / 3;
		c = c % 3 + c / 3;
	}
	//cout << l << " " << r << " " << mid << " " << sum << endl;
	if (r <= l) {
		cout << mid << endl;
	} else if (sum > n) { //说明估大了
		check(l, mid - 1);
	} else if (sum < n) {
		check(mid + 1, r);
	} else {
		cout << mid << endl;
	}
	return;
}

int main() {
	cin >> n;
	check(1, 100000000);
	return 0;
}

