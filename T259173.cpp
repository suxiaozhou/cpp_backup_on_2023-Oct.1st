#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int n, i;
double ans = 0;

struct st {
	int time, num;
} a[1010];

bool cmp(st x, st y) {
	if (x.time != y.time) {
		return y.time > x.time;
	}
	return y.num > x.num;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i].time;
		a[i].num = i;
	}
	sort(a, a + n, cmp);
	for (i = 0; i < n; i++) {
		ans += (n - i - 1) * a[i].time;
		cout << a[i].num + 1 << " ";
	}
	ans /= n;
	cout << endl << fixed << setprecision(2) << ans << endl;
	return 0;
}