#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
	int brother = -1;
	int father = -1;
	int son = -1;
	string data;
	string content;
};
string helpDoc = "";
const int MAX_NODES = 8000;
vector<Node> library(MAX_NODES);
int current = 1;
int libCount = 2;
bool stopFlag = false;
bool cdFlag = false;
bool importOpen = false;

string toLowerCase(string s) {
	string result = "";
	for (char c : s) {
		if (c >= 'A' && c <= 'Z') {
			result += c - 'A' + 'a';
		} else {
			result += c;
		}
	}
	return result;
}

int getLastBrother(int pos) {
	int lastBrother = pos;
	while (library[lastBrother].brother != -1) {
		lastBrother = library[lastBrother].brother;
	}
	return lastBrother;
}

void displayDirectory() {
	cout << "Name: " << library[current].data << endl;
	if (!importOpen) {
		cout << "Content: " << endl << "\"\"\"" << library[current].content << endl << "\"\"\"" << endl;
	}
	if (library[current].father != -1) {
		cout << "Father: " << library[library[current].father].data << endl;
	}
	cout << "Son list: " << endl;
	int next = library[current].son;
	while (next != -1) {
		cout << library[next].data << endl;
		next = library[next].brother;
	}
	cout << endl;
}

void deleteNode(const string &path) {
	cout << "Are you sure you want to delete this? (Y/N)" << endl;
	string sure;
	cin >> sure;
	if (sure == "Y") {
		int next = library[current].son;
		int deleteBrother = -1;
		while (next != -1) {
			if (library[next].data == path) {
				deleteBrother = next;
				cdFlag = true;
			}
			next = library[next].brother;
		}
		if (!cdFlag) {
			cout << "No such path named " << path << endl;
		} else {
			if (library[library[deleteBrother].father].son == deleteBrother) {
				library[library[deleteBrother].father].son = library[deleteBrother].brother;
			} else {
				for (int i = 1; i < libCount; i++) {
					if (library[i].brother == deleteBrother) {
						library[i].brother = library[deleteBrother].brother;
						break;
					}
				}
			}
			cout << "Deleting..." << endl;
			cout << "Success!" << endl;
		}
		cdFlag = false;
	} else {
		cout << "Canceled" << endl;
	}
}

void changeDirectory(const string &path) {
	if (path == "..") {
		if (library[current].father != -1) {
			current = library[current].father;
		} else {
			cout << "Error: This is the root directory!" << endl;
		}
	} else {
		int next = library[current].son;
		while (next != -1) {
			if (library[next].data == path) {
				current = next;
				cdFlag = true;
			}
			next = library[next].brother;
		}
		if (!cdFlag) {
			cout << "No such path named " << path << endl;
		}
		cdFlag = false;
	}
}

void saveTree(const string &path) {
	cout << "WARNING: This feature is currently experimental and may cause data loss or crashes. Use with caution!" << endl;
	cout << "Note: Content functionality may result in data loss!" << endl;
	ofstream outFile(path, ios::out | ios::binary);
	for (int i = 0; i < MAX_NODES; i++) {
		outFile.write(reinterpret_cast<char *>(&library[i]), sizeof(Node));
	}
	outFile.write(reinterpret_cast<char *>(&libCount), sizeof(libCount));
	outFile.close();
	cout << "Success" << endl;
}

void importTree(const string &path) {
	cout << "WARNING: This feature is currently experimental and may cause data loss or crashes. Use with caution!" << endl;
	cout << "Warning: This will overwrite your existing data. Continue? (Y/N)" << endl;
	string sure;
	cin >> sure;
	if (sure == "Y") {
		ifstream inFile(path, ios::in | ios::binary);
		if (!inFile) {
			cout << "File not found!" << endl;
			return;
		}
		inFile.read(reinterpret_cast<char *>(&library[0]), sizeof(Node) * MAX_NODES);
		inFile.read(reinterpret_cast<char *>(&libCount), sizeof(libCount));
		cout << "Read " << sizeof(Node) * MAX_NODES << " bytes, " << libCount << " nodes in total." << endl;
		inFile.close();
		importOpen = true;
		cout << "Content functionality has been disabled in the 'dir' command to prevent potential crashes." << endl;
	} else {
		cout << "Canceled" << endl;
	}
}

void newContent() {
	cout << "Enter content (type \";\" on a new line to stop):" << endl;
	if (!library[current].content.empty()) {
		library[current].content += "\n";
	}
	string content;
	while (getline(cin, content)) {
		if (content == ";") {
			break;
		}
		library[current].content += content + "\n";
	}
	cout << "Success! The content of this tree is:" << endl << "\"\"\"" << endl << library[current].content << "\"\"\"" <<
	     endl;
}

void outputContent() {
	if (library[current].content.empty()) {
		cout << "None" << endl;
	} else {
		cout << library[current].content << endl;
	}
}

void deleteContent() {
	cout << "The content of this tree is:" << endl << "\"\"\"" << endl << library[current].content << "\"\"\"" << endl;
	library[current].content = "";
	cout << "Success!" << endl;
}

int main() {
	if (true) {
		freopen("Õû»î.in", "r", stdin);
	}
	cout << "By suxiaozhou in April 2023, let's build trees!" << endl;
	cout << "Do not use double quotation marks. Thank you!" << endl;
	library[1].data = "gen";
	while (!stopFlag) {
		cout << "in >> ";
		string cmd;
		cin >> cmd;
		cmd = toLowerCase(cmd);
		if (cmd == "exit") {
			stopFlag = true;
		} else if (cmd == "new") {
			string newData;
			cin >> newData;
			if (library[current].son != -1) {
				library[getLastBrother(library[current].son)].brother = libCount;
			} else {
				library[current].son = libCount;
			}
			library[libCount].father = current;
			library[libCount].data = newData;
			libCount++;
		} else if (cmd == "dir") {
			cout << "Name: " << library[current].data << endl;
			if (!importOpen) {
				cout << "Content: " << endl << "\"\"\"" << endl << library[current].content << "\"\"\"" << endl;
			}
			if (library[current].father != -1) {
				cout << "Father: " << library[library[current].father].data << endl;
			}
			cout << "Child nodes: " << endl;
			int next = library[current].son;
			while (next != -1) {
				cout << library[next].data << endl;
				next = library[next].brother;
			}
			cout << endl;
		} else if (cmd == "del") {
			string path;
			cin >> path;
			cout << "Are you sure you want to delete this? (Y/N)" << endl;
			string sure;
			cin >> sure;
			if (sure == "Y") {
				int next = library[current].son, delB;
				while (next != -1) {
					if (library[next].data == path) {
						delB = next;
						cdFlag = true;
					}
					next = library[next].brother;
				}
				if (!cdFlag) {
					cout << "No such path named " << path << endl;
				} else {
					if (library[library[delB].father].son == delB) {
						library[library[delB].father].son = library[delB].brother;
					} else {
						for (int i = 1; i <= libCount; i++) {
							if (library[i].brother == delB) {
								library[i].brother = library[delB].brother;
								break;
							}
						}
					}
					cout << "Deleting..." << endl;
					cout << "Success!" << endl;
				}
				cdFlag = false;
			} else {
				cout << "Canceled" << endl;
			}
		} else if (cmd == "cd") {
			string path;
			cin >> path;
			if (path == "..") {
				if (library[current].father != -1) {
					current = library[current].father;
				} else {
					cout << "Error: This is the 'gen' node, it has no father!" << endl;
				}
			} else {
				int next = library[current].son;
				while (next != -1) {
					if (library[next].data == path) {
						current = next;
						cdFlag = true;
					}
					next = library[next].brother;
				}
				if (!cdFlag) {
					cout << "No such path named " << path << endl;
				}
				cdFlag = false;
			}
		} else if (cmd == "help") {
			cout << helpDoc << endl;
		} else if (cmd == "rename") {
			string rename;
			cin >> rename;
			library[current].data = rename;
			cout << "Rename success!" << endl;
		} else if (cmd == "show") {
			cout << "Building!" << endl;
		} else if (cmd == "save") {
			string path;
			cin >> path;
			saveTree(path);
		} else if (cmd == "import") {
			string path;
			cin >> path;
			importTree(path);
		} else if (cmd == "newcon") {
			newContent();
		} else if (cmd == "outcon") {
			outputContent();
		} else if (cmd == "delcon") {
			deleteContent();
		} else {
			cout << "Invalid command! Type 'help' to see the available commands." << endl;
		}
	}
	cout << "Bye!" << endl;
	return 0;
}


