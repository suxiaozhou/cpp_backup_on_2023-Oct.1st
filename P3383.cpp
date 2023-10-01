#include <bits/stdc++.h>
using namespace std;
bool isnt_prime[100000010];
int prime[10000010], n, q, cnt;

int main() {
	scanf("%d%d", &n, &q);
	isnt_prime[0] = isnt_prime[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (isnt_prime[i] == 0) {
			for (int j = i * 2; j <= n; j += i) {
				isnt_prime[j] = true;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isnt_prime[i] == 0) {
			prime[++cnt] = i;
		}
	}
	for (int i = 0, k; i < q; i++) {
		scanf("%d", &k);
		printf("%d\n", prime[k]);
	}
	return 0;
}

