#include <bits/stdc++.h>
using namespace std;
const int Num=1000010;
string str;
int a1[Num],a2[Num],b1[Num],b2[Num],x,orcnt=0,andcnt=0,testtmp=0;
int dfs(int l,int r){
    /*
    if (testtmp<5){
        cerr<<l<<" "<<r<<endl;
        cerr<<a1[r]<<endl;
        testtmp++;
    }
    */
    if (a1[r]>l){//重点
        int ans=dfs(l,a1[r]-1);
        if (ans==1){
            orcnt++;
            return 1;
        }
        return dfs(a1[r]+1,r);
    }
    if (a2[r]>l){//重点
        int ans=dfs(l,a2[r]-1);
        if (ans==0){
            andcnt++;
            return 0;
        }
        return dfs(a2[r]+1,r);
    }
    if (str[l]=='('&&str[r]==')'){
        return dfs(l+1,r-1);
    }
    return str[l]-'0';//重合了
}
int main(){
    cin>>str;
    int len=str.length();
    for (int i=0;i<len;i++){//预处理
        if (str[i]=='(') x++;
        else if (str[i]==')') x--;
        else if (str[i]=='|') b1[x]=i;
        else if (str[i]=='&') b2[x]=i;
        a1[i]=b1[x];
        a2[i]=b2[x];
    }
    cout<<dfs(0,len-1)<<endl<<andcnt<<" "<<orcnt<<endl;
    return 0;
}