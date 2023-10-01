#include <bits/stdc++.h>
using namespace std;
int n;

/*
				这题超难的
好好看注解，不然你永远猜不透你自己写的是什么鬼东西
        本题使用了门槛较低的递归写法。
听说还有一种位运算的写法，等我能力够了去探究探究……
*/
void find(int T) {
	cout << 2;//先输出2，所有输出都从他开始
	int num1 = 1, con = 0;
	//num1是最接近T的比T小的2的con次方的数
	while (T >= num1) {
		con++;
		num1 *= 2;
	}
	con--;
	/*
	说一下为什么没有con==1的选项，因为2^1输出得数2就可以了，而2已经在前面输出了。
	*/
	if (con == 2 || con == 0) {//con不用进行下一步运算了，因为已经化简到最简了
		cout << "(" << con << ")";
	} else if (con > 2) {//这种的con还是要继续化简
		cout << "(";
		find(con);
		cout << ")";
	}
	T -= num1 / 2;
	if (T) {//看看剩余的东西是否还需要多项式填补，如果T==0的话就不需要挂任何的多项式
		cout << "+";
		find(T);
	}
	return;
}

int main() {//正式运行！！
	cin >> n;
	find(n);
	return 0;
}