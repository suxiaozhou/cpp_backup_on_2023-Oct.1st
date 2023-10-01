#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int list[2501*25+5],l=0,h[2]={11,21},i,i1,w=0,l1=0;
char tmp;
int main(){
    while (1) {
        cin >> tmp;
        if(tmp == 'E') break;
        else if(tmp == 'W'){list[l] = 1;l++;}
        else if(tmp == 'L'){list[l] = 0;l++;}
    }
    for (i=0;i<2;i++){
        for (i1=0;i1<l;i1++){
            w+=list[i1];
            l1+=1-list[i1];
            if ((max(w,l1)>=h[i]&&abs(w-l1)>=2)||i1==l-1){
                cout<<w<<":"<<l1<<endl;
                w=0;l1=0;
            }
        }
        cout<<endl;
    }
    return 0;
}