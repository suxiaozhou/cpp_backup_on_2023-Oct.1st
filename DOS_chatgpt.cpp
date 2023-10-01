#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Node {
	int brother = -1; // 兄弟节点的索引
	int father = -1; // 父节点的索引
	int son = -1; // 子节点的索引
	int textnum = 0; // 当前节点下的文本文档数量
	string data; // 节点的名称（文件夹名或文本文档名）
	map<string, string> text; // 存储文本文档的内容，键为文档名，值为文档内容
};

vector<Node> lib; // 存储多叉树的容器，存放节点信息
int now = 1, libl = 2, stopflag = 0, cdflag = 0; // 当前节点索引、下一个节点索引、停止标志、切换目录标志

string toLowercase(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower); // 将字符串转换为小写
	return s;
}

int findLastChild(int pos) {
	int ans = pos;
	while (lib[ans].brother != -1) { // 找到最后一个子节点
		ans = lib[ans].brother;
	}
	return ans;
}

void printCurrentPath() {
	vector<int> path;
	int tmp = now;
	while (tmp != 1) {
		path.push_back(tmp); // 将路径中的节点索引存入容器
		tmp = lib[tmp].father;
	}
	cout << "\\";
	cout << lib[1].data;
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << "\\" << lib[path[i]].data; // 输出路径
	}
	cout << "\\";
}

void newFolder() {
	string newdata;
	cin >> newdata; // 输入新文件夹的名称
	if (lib[now].son != -1) {
		lib[findLastChild(lib[now].son)].brother = libl; // 在当前节点下添加新文件夹
	} else {
		lib[now].son = libl;
	}
	lib[libl].father = now;
	lib[libl].data = newdata;
	libl++; // 新节点索引自增
}

void showDirectory() {
	cout << "文件夹名称：" << lib[now].data << endl;
	int next = lib[now].son;
	cout << ".   文件夹" << endl;
	cout << "..   文件夹" << endl;
	while (next != -1) {
		cout << lib[next].data << "   文件夹" << endl; // 输出子文件夹
		next = lib[next].brother;
	}
	for (int i = 1; i <= lib[now].textnum; i++) {
		cout << lib[now].text_head_list[i] << "   文本文档" << endl; // 输出文本文档
	}
	cout << endl;
}

void deleteFolder() {
	string path;
	cin >> path; // 输入要删除的文件夹名称
	cout << "确定要删除吗？(Y/N)" << endl;
	string sure;
	cin >> sure;
	if (sure == "Y") {
		int next = lib[now].son, delb;
		while (next != -1) {
			if (lib[next].data == path) {
				delb = next;
				cdflag = 1;
			}
			next = lib[next].brother;
		}
		if (cdflag == 0) {
			cout << "没有名为 " << path << " 的路径" << endl;
		} else {
			if (lib[lib[delb].father].son == delb) {
				lib[lib[delb].father].son = lib[delb].brother; // 如果要删除的节点是父节点的第一个子节点，则将其兄弟节点升为第一个子节点
			} else {
				for (int i = 1; i <= libl; i++) {
					if (lib[i].brother == delb) {
						lib[i].brother = lib[delb].brother; // 修改兄弟节点的索引
						break;
					}
				}
			}
			cout << "删除成功！" << endl;
		}
		cdflag = 0;
	} else {
		cout << "取消删除" << endl;
	}
}

void changeDirectory() {
	string path;
	cin >> path; // 输入要切换的目录名称
	if (path == "..") {
		if (lib[now].father != -1) {
			now = lib[now].father; // 切换到父目录
		} else {
			cout << "错误：已经是根目录！" << endl;
		}
	} else {
		int next = lib[now].son;
		while (next != -1) {
			if (lib[next].data == path) {
				now = next; // 切换到指定的子目录
				cdflag = 1;
			}
			next = lib[next].brother;
		}
		if (cdflag == 0) {
			cout << "没有找到名为 " << path << " 的路径" << endl;
		}
		cdflag = 0;
	}
}

void help() {
	cout << "None :)" << endl; // 帮助文档
}

void renameFolder() {
	string renam;
	cin >> renam; // 输入新的文件夹名称
	lib[now].data = renam;
	cout << "重命名成功！" << endl;
}

void openText() {
	string path;
	cin >> path; // 输入要打开的文本文档名称
	if (lib[now].text.find(path) != lib[now].text.end()) {
		cout << lib[now].text[path] << endl; // 输出文本文档内容
	} else {
		cout << "没有找到名为 " << path << " 的文本文档" << endl;
	}
}

void createText() {
	string head, content;
	cin >> head >> content; // 输入文本文档的名称和内容
	lib[now].text[head] = content;
	lib[now].textnum++;
	cout << "创建成功" << endl;
}

int main() {
	cout << "by suxiaozhou in 2023 06, lets build!!" << endl;
	lib.resize(maxn); // 设置多叉树的容量
	lib[1].data = "root";
	while (!stopflag) {
		printCurrentPath();
		string cmd;
		cin >> cmd; // 输入命令
		cmd = toLowercase(cmd);
		if (cmd == "exit") {
			stopflag = true;
		} else if (cmd == "new_folder") {
			newFolder();
		} else if (cmd == "dir") {
			showDirectory();
		} else if (cmd == "del") {
			deleteFolder();
		} else if (cmd == "cd") {
			changeDirectory();
		} else if (cmd == "help") {
			help();
		} else if (cmd == "rename") {
			renameFolder();
		} else if (cmd == "open") {
			openText();
		} else if (cmd == "new_text") {
			createText();
		} else {
			cout << "错误：没有名为 \"" << cmd << "\" 的命令！" << endl;
		}
	}
	return 0;
}
