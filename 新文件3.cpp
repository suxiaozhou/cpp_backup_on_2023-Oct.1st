#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i += 4) { // 每 3 位一组
		int num = 0;
		for (int j = 0; j < 3 && i + j < len; j++) // 将三位八进制数转为十进制数
			num = num * 8 + s[i + j] - '0';
		printf("%X", num); // 输出对应的十六进制数
	}
	return 0;
}