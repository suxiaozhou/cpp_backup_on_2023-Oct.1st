#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 判断是否为逻辑运算符
bool isOperator(char c) {
	return c == '&' || c == '|';
}

// 计算逻辑表达式的值和短路次数
vector<int> evaluateExpression(string &expr) {
	stack<char> opStack;
	stack<int> valStack;
	int andShortcut = 0;
	int orShortcut = 0;

	for (char c : expr) {
		if (c == '(') {
			opStack.push(c);
		} else if (c == ')') {
			while (!opStack.empty() && opStack.top() != '(') {
				char op = opStack.top();
				opStack.pop();

				int val2 = valStack.top();
				valStack.pop();
				int val1 = valStack.top();
				valStack.pop();

				if (op == '&') {
					// 短路判断
					if (val1 == 0 || val2 == 0) {
						andShortcut++;
						valStack.push(0);
					} else {
						valStack.push(1);
					}
				} else if (op == '|') {
					// 短路判断
					if (val1 == 1 || val2 == 1) {
						orShortcut++;
						valStack.push(1);
					} else {
						valStack.push(0);
					}
				}
			}

			opStack.pop(); // 弹出 '('
		} else if (isOperator(c)) {
			while (!opStack.empty() && opStack.top() != '(' && ((c == '&' && opStack.top() == '|') || c == opStack.top())) {
				char op = opStack.top();
				opStack.pop();

				int val2 = valStack.top();
				valStack.pop();
				int val1 = valStack.top();
				valStack.pop();

				if (op == '&') {
					// 短路判断
					if (val1 == 0 || val2 == 0) {
						andShortcut++;
						valStack.push(0);
					} else {
						valStack.push(1);
					}
				} else if (op == '|') {
					// 短路判断
					if (val1 == 1 || val2 == 1) {
						orShortcut++;
						valStack.push(1);
					} else {
						valStack.push(0);
					}
				}
			}

			opStack.push(c);
		} else {
			// 处理数字字符 '0' 和 '1'
			int val = c - '0';
			valStack.push(val);
		}
	}

	// 处理剩余的运算符和操作数
	while (!opStack.empty()) {
		char op = opStack.top();
		opStack.pop();

		int val2 = valStack.top();
		valStack.pop();
		int val1 = valStack.top();
		valStack.pop();

		if (op == '&') {
			// 短路判断
			if (val1 == 0 || val2 == 0) {
				andShortcut++;
				valStack.push(0);
			} else {
				valStack.push(1);
			}
		} else if (op == '|') {
			// 短路判断
			if (val1 == 1 || val2 == 1) {
				orShortcut++;
				valStack.push(1);
			} else {
				valStack.push(0);
			}
		}
	}

	int result = valStack.top();
	valStack.pop();

	return {result, andShortcut, orShortcut};
}

int main() {
	freopen("P8815_chatgpt.in", "r", stdin);
	string expr;
	cin >> expr;

	vector<int> result = evaluateExpression(expr);

	cout << result[0] << endl;
	cout << result[1] << " " << result[2] << endl;

	return 0;
}

