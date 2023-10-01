#include <bits/stdc++.h>
using namespace std;
bool flag = false;
int K, i;

int main() {
	cin >> K;
	for (i = 10000; i <= 30000; i++) { //a1234-a1xxx
		if (i / 100 % K == 0 && (i / 10 - i / 10000 * 1000) % K == 0 && (i - i / 1000 * 1000) % K == 0) {
			cout << i << endl;
			flag = true;
		}
	}
	if (!flag) {
		cout << "No" << endl;
	}
	return 0;
}