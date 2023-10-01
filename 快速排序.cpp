#include <iostream>
using namespace std;
long long list[100010], n, i;

int qspx(long long qlist[], int l, int r) {
	int tmp, flag = qlist[(l + r) / 2];
	long long i = l, j = r;
	do {
		while (qlist[i] < flag) {
			i++;   //找着了
		}
		while (qlist[j] > flag) {
			j--;
		}
		if (i <= j) { //位置没过
			swap(qlist[i], qlist[j]);
			i++;
			j--;
		}
	} while (i <= j);
	//套娃
	if (l < j) {
		qspx(qlist, l, j);
	}
	if (i < r) {
		qspx(qlist, i, r);
	}
	return 0;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i];
	}
	qspx(list, 0, n - 1);
	for (i = 0; i < n; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
	return 0;
}