#include <bits/stdc++.h>
using namespace std;
int n, rl = 0, j, flag;
long long ans;

struct record {
	int time, price;
} r[100010];

int main() {
	cin >> n;
	for (int i = 1, tmp, tmp_price, tmp_time; i <= n; i++, flag = 0) {
		cin >> tmp >> tmp_price >> tmp_time;
		if (tmp == 0) {
			ans += tmp_price;
			r[++rl].time = tmp_time;
			r[rl].price = tmp_price;
		}
		if (tmp == 1) {
			for (j = max(rl - 45, 1); j <= rl; j++) {
				if (tmp_time - r[j].time <= 45 && tmp_price <= r[j].price && r[j].time != -1) {
					flag = 1;
					r[j].time = -1;
					break;
				}
			}
			if (!flag) {
				ans += tmp_price;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

