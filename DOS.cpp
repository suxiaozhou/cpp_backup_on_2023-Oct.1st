//coding=gb2312
/*
suxiaozhou 2023.06
a little DOS system in memory.
based by "多叉树"1.1 version.
*/
#include <bits/stdc++.h>
using namespace std;
string cmd, newdata, path, sure, renam, conten;
int now = 1, libl = 2, stopflag = 0, cdflag = 0, importopen = 0;
const int maxn = 8000;

struct lib_trees {
	int brother = -1, father = -1, son = -1, textnum = 0;
	string data, text_head_list[1000];
	map <string, string> text;
} lib[maxn];

string bigli(string s) {
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

int bll(int pos) {
	int ans = pos;
	while (lib[ans].brother != -1) {
		ans = lib[ans].brother;
	}
	return ans;
}
const string helpdocm = "None :)";

int main() {
	if (0 == 1) {//调试模式
		freopen("整活.in", "r", stdin);
	}
	cout << "by suxiaozhou in 2023 06,lets build!!" << endl;
	lib[1].data = "root";
	while (!stopflag) {

		int cnt = 0, llll[8010], tmp = now;
		while (tmp != 1) {
			llll[cnt] = tmp;
			cnt++;
			tmp = lib[tmp].father;
		}
		cout << "\\" << lib[1].data;
		for (int i = cnt - 1; i >= 0; i--) {
			cout << "\\" + lib[llll[i]].data;
		}
		cout << "\\";
		cnt = 0, tmp = 0;

		cin >> cmd;
		cmd = bigli(cmd);
		if (cmd == "exit") {
			stopflag = true;
		} else if (cmd == "new_folder") {
			cin >> newdata;
			if (lib[now].son != -1) {
				lib[bll(lib[now].son)].brother = libl;
			} else {
				lib[now].son = libl;
			}
			lib[libl].father = now;
			lib[libl].data = newdata;
			libl++;
		} else if (cmd == "dir") {
			cout << "folder name:" << lib[now].data << endl;
			int next = lib[now].son;
			cout << ".   Folder" << endl;
			cout << "..   Folder" << endl;
			while (next != -1) {
				cout << lib[next].data << "   Folder" << endl;
				next = lib[next].brother;
			}
			for (int i = 1; i <= lib[now].textnum; i++) {
				cout << lib[now].text_head_list[i] << "   TextDoc" << endl;
			}
			cout << endl;
		} else if (cmd == "del") {
			//删完爸爸删哥哥
			cin >> path;
			cout << "Are you sure delete it?(Y/N)" << endl;
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
					cout << "No such path named " << path << endl;
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
					cout << "Success!!" << endl;
				}
				cdflag = 0;
				//从此，再无人记得他的存在。。。
			} else {
				cout << "Canceled" << endl;
			}
		} else if (cmd == "cd") {
			cin >> path;
			if (path == "..") {
				if (lib[now].father != -1) {
					now = lib[now].father;
				} else {
					cout << "Error:this is root!" << endl;
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
					cout << "No find path named " << path << endl;
				}
				cdflag = 0;
			}
		} else if (cmd == "help") {
			cout << helpdocm << endl;
		} else if (cmd == "rename") {
			cin >> renam;
			lib[now].data = renam;
			cout << "Rename success!!" << endl;
		} else if (cmd == "open") {
			cin >> path;
			if (lib[now].text.find(path) != lib[now].text.end()) { //如果能找到的话
				cout << lib[now].text[path] << endl;
			} else {
				cout << "Not find text named " << path << endl;
			}
		} else if (cmd == "new_text") {
			string content, head;
			cin >> head >> content;
			lib[now].text[head] = content;
			lib[now].text_head_list[++lib[now].textnum] = head;
			cout << "success" << endl;

		} else {
			cout << "Error:No command named\"" << cmd << "\"!" << endl;
		}
	}
	return 0;
}

