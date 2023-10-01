#include <iostream>
#include <algorithm>
using namespace std;
char cganbu, cxibu;
long long allmoney = 0;
int n, i;

struct student {
	char name;
	int lscore, dscore, write, money = 0, xulie;
	bool ganbu, fromwest;
};
struct student list[110];

bool cmp(struct student a, struct student b) {
	if (a.money != b.money) {
		return a.money < b.money;
	}
	return a.xulie > b.xulie;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i].name >> list[i].lscore >> list[i].dscore >> cganbu >> cxibu >> list[i].write;
		list[i].ganbu = cganbu == 'Y';
		list[i].fromwest = cxibu == 'Y';
		list[i].xulie = i;
		if (list[i].write > 0 && list[i].lscore > 80) {
			list[i].money += 8000;
		}
		if (list[i].lscore > 80 && list[i].dscore > 80) {
			list[i].money += 4000;
		}
		if (list[i].lscore > 90) {
			list[i].money += 2000;
		}
		if (list[i].lscore > 85 && list[i].fromwest) {
			list[i].money += 1000;
		}
		if (list[i].ganbu && list[i].dscore > 80) {
			list[i].money += 850;
		}
		allmoney += list[i].money;
	}
	sort(list, list + n, cmp);
	cout << list[i].name << endl << list[i].money << endl << allmoney << endl;
	return 0;
}