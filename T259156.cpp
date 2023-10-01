#include <iostream>
#include <string>
using namespace std;
long long M, C, O, I, i, n;
string p;

int main() {
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> p;
		if (p[0] == 'M') {
			M++;
		} else if (p[0] == 'C') {
			C++;
		} else if (p[0] == 'O') {
			O++;
		} else if (p[0] == 'I') {
			I++;
		}
	}
	long long ans = M * C * O + M * C * I + M * O * I + C * O * I;
	cout << ans << endl;
	return 0;
}