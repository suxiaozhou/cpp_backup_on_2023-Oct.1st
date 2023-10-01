#include <map>
#include <iostream>
#include <string>
using namespace std;
map <string, int> m;
int n, cmd, score;
string name;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> name >> score;
			m[name] = score;
			cout << "OK" << endl;
		} else if (cmd == 2) {
			cin >> name;
			if (m.find(name) == m.end()) {
				cout << "Not found" << endl;
				continue;
			}
			cout << m[name] << endl;
		} else if (cmd == 3) {
			cin >> name;
			if (m.find(name) == m.end()) {
				cout << "Not found" << endl;
				continue;
			}
			m.erase(name);
			cout << "Deleted successfully" << endl;
		} else {
			cout << m.size() << endl;
		}
	}
	return 0;
}

