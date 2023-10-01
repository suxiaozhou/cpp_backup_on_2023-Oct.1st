#include <bits/stdc++.h>
using namespace std;
//贪心
long long money;
int n, tmp, la[110], lb[110];

bool cmp(int a, int b) {
	return a < b;
}

int min_m(int a, int b) {
	if (a > b) {
		return b;
	}
	return a;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		la[tmp]++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		lb[tmp]++;
	}
	for (int i = 0; i <= 100; i++) { //能拿钱就先拿钱
		for (int j = i - 1; j >= 0 && la[i] != 0; j--) {
			tmp = min_m(la[i], lb[j]);
			la[i] -= tmp;
			lb[i] -= tmp;
			money += tmp;
		}
	}
	for (int i = 0; i <= 100; i++) {//平局
		if (lb[i] != 0 && la[i] != 0) {
			tmp = min_m(la[i], lb[i]);
			la[i] -= tmp;
			lb[i] -= tmp;
		}
	}
	for (int i = 0; i <= 100; i++) {
		money -= lb[i];
	}
	money *= 200;
	cout << money << endl;
	return 0;
}

