#include <bits/stdc++.h>
using namespace std;
#define ll int
ll a[1000010];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("sort+quqian20.in", "r", stdin);
	for (int i = 1; i <= 1000000; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1000001, cmp);
	for (int i = 1; i <= 20; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}

