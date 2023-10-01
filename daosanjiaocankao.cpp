

#include <iostream>
using namespace std;
int main() 
{
	int n;
	cin >> n;
	//i代表行
	for (int i = 0; i < n; i++)
	{	//1.先解决空格问题
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		//2.输出#的个数为：2*(n-当前行)-1
		for (int k = 0; k < 2*(n-i)-1; k++)
		{
			cout << "#";
		}
		//3.第三个问题要解决的换行
		cout << endl;
	}
	//system("pause");
	return 0;
}
