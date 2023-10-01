#include<bits/stdc++.h>
using namespace std;
#define N 1005
int main()
{
    char s[N], v;//s:公式字符串 v:未知数字母 
    cin >> s;
    int len = strlen(s), num = 0, sign = 1;//num：构造出的数字 sign:构造出的数字的符号 
    int ln = 0, rn = 0;//ln:等号左侧未知数的系数和 rn:等号右侧常数和 
    bool isLeft = true;//是否在遍历等号左边 
    for(int i = 0; i <= len; ++i)//遍历包括最后的'\0' 
    {
        if(s[i] >= '0' && s[i] <= '9')//如果是数字，则构造数字 
            num = num * 10 + s[i] - '0';
        else
        {
            if(s[i] >= 'a' && s[i] <= 'z')//如果是未知数 
            {
                v = s[i];//确定未知数字母 
                if(isLeft == false)//如果是右侧的项，则移动到左侧，系数符号改变 
                    sign = -sign;
                if(num == 0)
                	num = 1;
                ln += sign * num;//未知数系数增加sign*num 
            }
            else//如果是常数项 
            {//如果s[i]是'\0'且最后一个字符是字母，那么会运行到这一句，此时num为0，不影响rn的值 
                if(isLeft)//如果是左侧的项，移动到右侧后系数符号改变 
                    sign = -sign;
                rn += sign * num;//右侧常数增加sign*num 
            }
            sign = 1;//符号还原为正 
            num = 0;//构造数字变量归0 
            if(s[i] == '-')//下一个数字符号位负 
                sign = -1;
            else if(s[i] == '=')//经过等号，后面就是等号右边的式子了 
                isLeft = false;
        }
    }
    cout << v << '=';
	if(rn == 0)
		cout << fixed << setprecision(3) << 0.0;
	else 
    	cout << fixed << setprecision(3) << (double)rn / ln;
	return 0;
}
