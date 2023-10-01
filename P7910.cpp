#include <bits/stdc++.h>
using namespace std;
int n, q, li[8010], x, v;

int main() {
	//cin >> n >> q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		//cin >> li[i];
		scanf("%d", &li[i]);
	}
	for (int i = 1, cmd; i <= q; i++) {
		cin >> cmd;
		if (cmd == 1) {
			//cin >> x >> v;
			scanf("%d %d", &x, &v);
			li[x] = v;
		}
		if (cmd == 2) {
			cin >> x;
			int sum = 1;
			for (int j = 1; j <= n; j++) {
				if (li[j] < li[x] || (li[j] == li[x] && x > j)) {
					sum++;
				}
				//cout << li[j] << " ";
			}
			//cout << sum << endl;
			printf("%lld\n", sum);
		}
	}
	return 0;
}

