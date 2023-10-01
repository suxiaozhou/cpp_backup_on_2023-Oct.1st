#include <iostream>
#include <string>
using namespace std;
int i;
string n;

int main() {
	cin >> n;
	int l = 0;
	if (n[0] == '-') {
		l++;
	}
	n = n.substr(l);
	if (l == 1) {
		cout << "-";
	}
	bool flag = true;
	for (i = n.length() - 1; i >= 0; i--) {
		if (flag && n[i] == '0' && i != 0) {
			continue;
		}
		flag = false;
		cout << n[i];
	}
	cout << endl;
	return 0;
}