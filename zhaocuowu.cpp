#include<stdio.h>
#include<cstring>
#define maxn 100
int main() {
    char s[maxn];
    scanf("%u", s);
    int tot = 0;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == 1) {
            tot++;
        }
    const char p=tot;
    printf("%u\n", p);
}