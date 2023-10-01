#include <bits/stdc++.h>
using namespace std;

/*
这题说着像队列，但怎么看怎么像链表
又有点像链表与队列的结合体……
注意最大时间复杂度为n log(n)
*/
struct classmate {
	int l = -1, r = -1, outflag = 1;
} cml[100010];
int n, i, k, p, m, nextn = 1;

int main() {
	cin >> n;
	int cmll = 1, cmlr = n;
	for (i = 2; i <= n; i++) {//build
		cin >> k >> p;
		if (p == 0) {
			if (cml[k].l != -1) {
				cml[cml[k].l].r = i;
				cml[i].l = cml[k].l;
			}
			cml[k].l = i;
			cml[i].r = k;
		} else {
			if (cml[k].r != -1) {
				cml[cml[k].r].l = i;
				cml[i].r = cml[k].r;
			}
			cml[k].r = i;
			cml[i].l = k;
		}
	}

	cin >> m;
	for (i = 0; i < m; i++) {//remove
		cin >> p;
		cml[p].outflag = 0;
	}
	for (i = 1; i <= n; i++) {
		if (cml[i].l == -1 && cml[i].r != -1) {
			nextn = i;
			break;
		}
	}
	while (nextn != -1) {
		if (cml[nextn].outflag == 1) {
			cout << nextn << " ";
		}
		nextn = cml[nextn].r;
	}
	cout << endl;
	return 0;
}