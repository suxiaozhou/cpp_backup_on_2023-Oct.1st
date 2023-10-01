#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, i;

struct stu {
	string name;
	int y, m, d, code;
} list[110];

bool cmp(struct stu a, struct stu b) { //Ð¡ÔÚÇ°
	if (a.y != b.y) {
		return a.y > b.y;
	}
	if (a.m != b.m) {
		return a.m > b.m;
	}
	if (a.d != b.d) {
		return a.d > b.d;
	}
	return a.code < b.code;
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i].name >> list[i].y >> list[i].m >> list[i].d;
		list[i].code = i;
	}
	sort(list, list + n, cmp);
	for (i = n - 1; i >= 0; i--) {
		cout << list[i].name << endl;
	}
	return 0;
}