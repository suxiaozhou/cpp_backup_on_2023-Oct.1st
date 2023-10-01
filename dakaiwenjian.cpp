#include <iostream>
#include <stdio.h>
using namespace std;
//1.基本操作
//1.1write
//1.1.1fprintf
int write(){
    FILE * fp;
    fp = fopen ("file0.out","w+");
    fprintf(fp, "%s", "hi");
    fclose(fp);
    return 0;
}
//1.1.2fputs(不包括空字符)
int write2(){
    FILE *fp;
    fp = fopen("file0.out", "w+");
    fputs("hi", fp);
    fclose(fp);
    return 0;
}
//1.2read
//1.2.1(fscanf)
int read_fscanf(){
    FILE * fp;
    char str;
    fp=fopen("file0.out","w+");
    fscanf(fp,"%c",str);
    cout<<str<<endl;
    fclose(fp);
    return 0;
}
//1.2.2(fgetc)
int read_fgetc(){
    FILE *fp;
    char str2;
    fp=fopen("flie0.out","r");
    str2=fgetc(fp);
    cout<<str2<<endl;
    fclose(fp);
    return 0;
}
//1.3check
//1.3.1 do code(open) have error?(perror)
int error(){
    FILE *fp;
    fp=fopen("djshfsdhf.txt","r");
    if (fp==NULL){
        perror("ERROR:");
        return -1;
    }
}
//1.3.2 do txt have words?(feof)
int have(){
    FILE *fp;
    fp=fopen("file0.out","r");
    if (feof(fp)){
        cout<<"NO ANY WORDS!!"<<endl;
    }
}
//1.4other
int restart_open(){
    FILE* fp;
    fp=fopen("file0.out","w+");
    //将指针重新移到开头
    rewind(fp);
    return 0;
}
//do (main)
int main(){
    write();
    return 0;
}