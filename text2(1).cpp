//
// Created by sxz on 22-7-27.
//
#include <iostream>
using namespace std;
int main()
{
    int sum=0,num=1;
    while (num<=1000){
        sum+=num;
        ++num;
    }
    std::cout<<'hello'
        <<sum<<std::endl;
    return 0;
}