#include <bits/stdc++.h>
using namespace std;
int lena, lenb, a[100], b[100], tmp;
string out = "";

int main() {
	cin >> lena;
	for (int i = 1; i <= lena; i++) {
		cin >> tmp;
		a[tmp] = 1;
	}
	cin >> lenb;
	for (int i = 1; i <= lenb; i++) {
		cin >> tmp;
		b[tmp] = 1;
	}
	cout << lena << endl;

	for (int i = 0; i <= 65; i++) {
		if (a[i] && b[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	out = "";
	for (int i = 0; i <= 65; i++) {
		if (a[i] || b[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}

