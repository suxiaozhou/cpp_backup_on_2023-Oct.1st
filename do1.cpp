#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    FILE * fp;
    char str;
    fp=fopen("file0.out","w+");
    fscanf(fp,"%c",str);
    cout<<str<<endl;
    fclose(fp);
    return 0;
}