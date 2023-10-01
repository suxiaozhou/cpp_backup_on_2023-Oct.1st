#include <bits/stdc++.h>
using namespace std;
int n;

struct trees {
	int l = 0, r = 0;
} t[1000010];

void pre_order(int x) {
	cout << x << " ";
	if (t[x].l) {
		pre_order(t[x].l);
	}
	if (t[x].r) {
		pre_order(t[x].r);
	}
}

void in_order(int x) {
	if (t[x].l) {
		in_order(t[x].l);
	}
	cout << x << " ";
	if (t[x].r) {
		in_order(t[x].r);
	}
}

void past_order(int x) {
	if (t[x].l) {
		past_order(t[x].l);
	}
	if (t[x].r) {
		past_order(t[x].r);
	}
	cout << x << " ";
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].l >> t[i].r;
	}
	pre_order(1);
	cout << endl;
	in_order(1);
	cout << endl;
	past_order(1);
	cout << endl;
	return 0;
}

