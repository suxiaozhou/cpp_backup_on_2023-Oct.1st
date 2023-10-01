#include <iostream>
using namespace std;

int nxt[110], n, m, last;

int main() {
	cin >> n >> m; // 输入约瑟夫环的总人数n和报数的数字m

	// 初始化约瑟夫环
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			nxt[i] = i + 1; // 设置每个人的下一个人的编号
		} else {
			nxt[i] = 1; // 最后一个人的下一个人是第一个人
		}
	}

	int now = 1; // 当前报数的人的编号
	while (nxt[now] != now) { // 当约瑟夫环中只剩下一个人时结束循环
		// 找到第m个报数的人
		for (int i = 1; i <= m; i++) {
			if (i == m) {
				last = now; // 记录上一个报数的人的编号
			}
			now = nxt[now]; // 移动到下一个报数的人
		}

		if (now != 1) {
			cout << now - 1; // 输出当前报数的人的编号（减去1是因为编号从1开始）
		} else {
			cout << n; // 如果当前报数的人是第一个人，则输出总人数n
		}

		if (nxt[now] != now) {
			cout << " "; // 如果约瑟夫环中还有多个人，则输出空格
		}

		nxt[last] = nxt[now]; // 将上一个报数的人的下一个人设为当前报数的人的下一个人，实现删除当前报数的人
	}

	return 0;
}
