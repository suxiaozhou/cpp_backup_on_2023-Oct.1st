#include <iostream>
#include <algorithm>
using namespace std;
int i, n, math, english;

struct student {
	int code, chinese, allscore;
};
struct student list[310];

bool cmp(struct student a, struct student b) { //b<a
	if (a.allscore != b.allscore) {
		return b.allscore < a.allscore;
	} else if (a.chinese != b.chinese) {
		return b.chinese < a.chinese;
	}
	return b.code > a.code;//注意小在前
}

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> list[i].chinese >> math >> english;
		list[i].allscore = list[i].chinese + math + english;
		list[i].code = i + 1;
	}
	sort(list, list + n, cmp);
	for (i = 0; i < 5; i++) {
		cout << list[i].code << " " << list[i].allscore << endl;
	}
	return 0;
}