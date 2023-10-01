#include <iostream>
using namespace std;
int n, i, j, money = 0, flag;

struct l {
	int j1, pri, time, u;
} list[100010];

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i].j1 >> list[i].pri >> list[i].time;
	}
	for (i = 0; i < n; i++) {
		if (!list[i].j1) {
			money += list[i].pri;
			list[i].u = 1;
		} else {
			flag = 0;
			for (j = max(i - 46, 0); j < i; j++) {
				if (list[j].j1 == 0 && list[j].pri >= list[i].pri && list[i].u == 1 && list[i].time - list[j].time <= 45) {
					list[j].u = 0;
					flag = 1;
					break;
				}
			}
			if (!flag) {
				money += list[i].pri;
			}
		}
	}
	cout << money << endl;
	return 0;
}