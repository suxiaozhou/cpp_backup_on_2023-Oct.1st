#include <bits/stdc++.h>
using namespace std;
int k;

struct MSG {
	string addr;
	int note;
	void msg(string addre, int notee) {
		addr = addre;
		note = notee;
		return;
	}
};
vector <MSG> addli;

bool solve(string s, int mode) {
	if (s == "0") {
		return 0;
	}
	int len = s.length();
	if (s[0] == '0' || len == 0) {
		return 1;
	}
	if (mode == 0) {
		if (len > 3) {
			return 1;
		}
		int sum = 0;
		for (int i = len - 1, w = 1; i >= 0; i--, w *= 10) {
			sum += (s[i] - '0') * w;
		}
		if (sum > 255) {
			return 1;
		}
	}
	if (mode == 1) {
		if (len > 5) {
			return 1;
		}
		int sum = 0;
		for (int i = len - 1, w = 1; i >= 0; i--, w *= 10) {
			sum += (s[i] - '0') * w;
		}
		if (sum > 65535) {
			return 1;
		}
	}
	//cout << "tag" << endl;
	return 0;
}

bool is_err(string addr) {
	int dot_cnt = 0, m_cnt = 0, dot_pos[5], m_pos[3];
	for (int i = 0; i < addr.length(); i++) {
		if (addr[i] == '.') {
			dot_cnt++;
			dot_pos[dot_cnt] = i;
		} else if (addr[i] == ':') {
			m_cnt++;
			m_pos[m_cnt] = i;
		} else {
			if (addr[i] - '0' < 0 || addr[i] - '0' > 9) {
				return 1;
			}
		}
		if (dot_cnt > 3 || m_cnt > 1) {
			return 1;
		}
	}
	if (dot_cnt != 3 || m_cnt != 1) {
		return 1;
	}
	string s1, s2, s3, s4, s;
	s1 = s2 = s3 = s4 = s = addr;
	s1 = s1.substr(0, dot_pos[1]);
	s2 = s2.substr(dot_pos[1] + 1, dot_pos[2]  - (dot_pos[1] + 1));
	s3 = s3.substr(dot_pos[2] + 1, dot_pos[3] - (dot_pos[2] + 1));
	s4 = s4.substr(dot_pos[3] + 1, m_pos[1] - (dot_pos[3] + 1));
	s = s.substr(m_pos[1] + 1, s.length()  - (m_pos[1] - 1));
	return solve(s1, 0) || solve(s2, 0) || solve(s3, 0) || solve(s4, 0) || solve(s, 1);
}

int main() {
	//freopen("network3.in", "r", stdin);
	cin >> k;
	for (int i = 1; i <= k; i++) {
		string addr, obj;
		cin >> obj;
		if (obj == "Server") {
			cin >> addr;
			if (is_err(addr)) {
				cout << "ERR" << endl;
				continue;
			}
			bool flag = 0;
			for (int j = 0; j < addli.size(); j++) {
				if (addli[j].addr == addr) {
					cout << "FAIL" << endl;
					flag = 1;
					continue;
				}
			}
			if (flag) {
				continue;
			}
			MSG msg;
			msg.addr = addr;
			msg.note = i;
			addli.push_back(msg);
			cout << "OK" << endl;
		}
		if (obj == "Client") {
			cin >> addr;
			if (is_err(addr)) {
				cout << "ERR" << endl;
				continue;
			}
			bool flag = 0;
			for (int j = 0; j < addli.size(); j++) {
				if (addli[j].addr == addr) {
					cout << addli[j].note << endl;
					flag = 1;
					continue;
				}
			}
			if (!flag) {
				cout << "FAIL" << endl;
			}
		}
	}
	return 0;
}

