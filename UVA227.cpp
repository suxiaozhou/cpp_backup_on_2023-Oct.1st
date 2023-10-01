#include <cstdio>
#include <iostream>
using namespace std;
void Swap(char &s1,char &s2);

int main()
{
    char ans,s[5][5];
    int dx,dy,Case=0;//用于储存空格位置
    while(true){
      bool flag=true;
      for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
          scanf("%c",&s[i][j]);
          if(s[0][0]=='Z')  return 0;
          if(s[i][j]==' '){
            dx=i; dy=j;
          }
        }
        getchar();
      }
      while((ans=getchar())!='0'){
        if(ans=='A'&&dx-1>=0){
            Swap(s[dx][dy],s[dx-1][dy]);
            dx-=1;
        }
        else if(ans=='B'&&dx+1<=4){
            Swap(s[dx][dy],s[dx+1][dy]);
            dx+=1;
        }
        else if(ans=='L'&&dy-1>=0){
            Swap(s[dx][dy],s[dx][dy-1]);
            dy-=1;
        }
        else if(ans=='R'&&dy+1<=4){
            Swap(s[dx][dy],s[dx][dy+1]);
            dy+=1;
        }
        else if(ans!='\n') flag=false;
      }
      getchar();
      if(Case)  printf("\n");
      printf("Puzzle #%d:\n",++Case);
      if(flag){
        for(int i=0;i<5;i++){
          for(int j=0;j<5;j++)
            if(!j) printf("%c",s[i][j]);
            else printf(" %c",s[i][j]);
            printf("\n");
        }
      }
      else
        printf("This puzzle has no final configuration.\n");
    }
    return 0;
}
void Swap(char &s1,char &s2){
    char c=s1;
    s1=s2;
    s2=c;
}