#include <bits/stdc++.h>
//gb2312  suxiaozhou 2023.07
using namespace std;
string cmd, path;
int now = 1, libl = 2, stopflag = 0, cdflag = 0;

struct lib_trees {
	int brother = -1, father = -1, son = -1;
	string data;
};
vector <lib_trees> lib(11 % 114514);

string LOWERCASE(string s) {
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] <= 'Z' && s[i] >= 'A') {
			ans += s[i] - 'A' + 'a';
		} else {
			ans += s[i];
		}
	}
	return ans;
}

int brother_in_the_end(int pos) {//末端兄弟
	int ans = pos;
	while (lib[ans].brother != -1) {
		ans = lib[ans].brother;
	}
	return ans;
}

void make_dir() {
	string newdata;
	cin >> newdata;
	if (lib[now].son != -1) {
		lib[brother_in_the_end(lib[now].son)].brother = libl;
	} else {
		lib[now].son = libl;
	}
	if (libl >= lib.size() - 1) {
		lib.resize(lib.size() + 20);
	}
	lib[libl].father = now;
	lib[libl].data = newdata;
	libl++;
}

void dir_things() {
	cout << "his name is:" << lib[now].data << endl;
	if (lib[now].father != -1) {
		cout << "His father is:" << lib[lib[now].father].data << endl;
	}
	cout << "son list:" << endl;
	int next = lib[now].son;
	while (next != -1) {
		cout << lib[next].data << endl;
		next = lib[next].brother;
	}
	cout << endl;
}

void delet() {
	string sure;
	//删完爸爸删哥哥
	cin >> path;
	cout << "Are you sure delete this one?(Y/N)" << endl;
	cin >> sure;
	if (sure == "Y") {
		//
		int next = lib[now].son, delb;
		while (next != -1) {
			if (lib[next].data == path) {
				delb = next;
				cdflag = 1;
			}
			next = lib[next].brother;
		}
		if (cdflag == 0) {
			cout << "No path named " << path << endl;
		} else {
			if (lib[lib[delb].father].son == delb) { //如果他是长子的话
				lib[lib[delb].father].son = lib[delb].brother; //他的兄弟继承他的地位,同时让爸爸把他忘得一干二净
			} else { //说明只有一个兄弟记得他
				for (int i = 1; i <= libl; i++) {
					//找到记得他的人了！
					if (lib[i].brother == delb) {
						lib[i].brother = lib[delb].brother; //直接记忆到下个兄弟
						break;
					}
				}
			}
			cout << "deleteing..." << endl;
			cout << "Success!!" << endl;
		}
		cdflag = 0;
		//从此，再无人记得他的存在。。。
	} else {
		cout << "Canceled" << endl;
	}
}

void cd_dir() {
	cin >> path;
	if (path == "..") {
		if (lib[now].father != -1) {
			now = lib[now].father;
		} else {
			cout << "Error:this is gen,it have not any father!" << endl;
		}
	} else {
		int next = lib[now].son;
		while (next != -1) {
			if (lib[next].data == path) {
				now = next;
				cdflag = 1;
			}
			next = lib[next].brother;
		}
		if (cdflag == 0) {
			cout << "No path named " << path << endl;
		}
		cdflag = 0;
	}
}

void rename_f() {
	string renam;
	cin >> renam;
	lib[now].data = renam;
	cout << "Rename success!!" << endl;
}

const string helpdocm = "None :)";

int main() {
	cout << "by suxiaozhou in 2023 July,lets build trees!!" << endl;
	//调试模式
	//freopen("整活.in", "r", stdin);
	//cout << "do not press (ascll=32),thanks you!" << endl;
	lib[1].data = "main";
	while (!stopflag) {
		cout << "input>>";
		cin >> cmd;
		cmd = LOWERCASE(cmd);
		if (cmd == "exit") {
			stopflag = true;
		} else if (cmd == "mkdir") {
			make_dir();
		} else if (cmd == "dir") {
			dir_things();
		} else if (cmd == "del") {
			delet();
		} else if (cmd == "cd") {
			cd_dir();
		} else if (cmd == "help") {
			cout << helpdocm << endl;
		} else if (cmd == "rename") {
			rename_f();
		} else {
			cout << "Error:No command named " << cmd << "! Please try again!" << endl;
		}
	}
	cout << "Good Bye!" << endl;
	return 0;
}
