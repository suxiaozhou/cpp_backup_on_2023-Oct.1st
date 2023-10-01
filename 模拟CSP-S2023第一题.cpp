#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 找到第一个非单调递增的位置
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[i + 1]) {
			pos = i;
			break;
		}
	}

	// 如果整个序列都是单调递增或递减的，则不需要操作
	if (pos == -1) {
		cout << 0 << endl;
		return 0;
	}

	// 将第一个非单调递增的位置和后面的一个位置交换
	swap(a[pos], a[pos + 1]);

	// 统计操作次数
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] > a[i + 1]) && (a[i + 1] > a[i + 2])) {
			ans++;
		} else if ((a[i] < a[i + 1]) && (a[i + 1] < a[i + 2])) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}