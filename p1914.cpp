#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int n,i;
    char list[50],p;
    scanf("%d%s",&n,list);
    for (i=0;list[i]!='\0';i++){
        p=(list[i]-'a'+n)%26+'a';
        cout<<p;
    }
    cout<<endl;
    return 0;
}