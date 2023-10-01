#include <bits/stdc++.h>
using namespace std;
int n;
char root;

struct trees {
	char l = 0, r = 0;
} t[30];

void pre_order(int x) {
	cout << char(x);
	if (t[x].l != '*') {
		pre_order(t[x].l);
	}
	if (t[x].r != '*') {
		pre_order(t[x].r);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		if (i == 1) {
			root = tmp[0];
		}
		t[tmp[0]].l = tmp[1];
		t[tmp[0]].r = tmp[2];
	}
	pre_order(root);
	cout << endl;
	return 0;
}
