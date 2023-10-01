#include <bits/stdc++.h>
using namespace std;
int n, x, tmpl, tmpr;
long long ans = 0;
/*
struct QAQ{
    int l,r;
}li[500010];
*/

int main() {
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> tmpl >> tmpr;
		//li[i].l=min(tmpl,tmpr),li[i].r=max(tmpl,tmpr);
		if (x < tmpl) {
			ans += tmpl - x;
			x = tmpl;
		}
		if (x > tmpr) {
			ans += x - tmpr;
			x = tmpr;
		}
	}
	cout << ans << endl;
	return 0;
}
