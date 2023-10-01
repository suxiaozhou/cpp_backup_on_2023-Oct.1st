#include <bits/stdc++.h>
using namespace std;
int A, B, L, i, j, ansA, ansB;
double minnum = 10000000;

int main() {
	cin >> A >> B >> L;
	for (i = 1; i <= L; i++) {
		for (j = 0; j <= L; j++) {
			if (1.0 * i / j >= 1.0 * A / B && 1.0 * i / j - 1.0 * A / B < minnum) {
				minnum = 1.0 * i / j - 1.0 * A / B;
				ansA = i;
				ansB = j;
			}
		}
	}
	cout << ansA << " " << ansB << endl;
	return 0;
}