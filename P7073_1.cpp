#include <bits/stdc++.h>
using namespace std;
string str,code="";
int n;
bool vis[100010],ans;//vis:遇到短路
//废了

bool solve(int l,int r){
    if (code[r]>='0'&&code[r]<='9'){//只剩数字
        int num=0,pow=1;
        for (int i=r;i>=l+1;i--,pow*=10){
            num+=(code[i]-'0')*pow;
        }
        vis[num]=1;
        return 0;
    }
    if (code[r]=='!'){
        return !solve(l,r-1);
    }
    //区分左右子树
    int pos=-1;//左子树最后一位
    for (int i=l+1;i<r;i++){
        if (code[i-1]>='0'&&code[i-1]<='9'){
            if (code[i]=='|'||code[i]=='&'){
                if (code[i+1]=='x'){
                    pos=i;
                    break;
                }
            }
        }
    }
    //
    if (code[r]=='|'){
        if (solve(l,pos)){
            return 1;
        }
        return solve(pos+1,r-1);
    }
    if (code[r]=='&'){
        if (!solve(l,pos)){
            return 0;
        }
        return solve(pos+1,r-1);
        //return solve(l,pos)&&solve(pos+1,r-1);
    }
}
int main(){
    getline(cin,str);
    cin>>n;
    for (int i=0;i<str.length();i++){
        if (str[i]==' '){
            continue;
        }
        code+=str[i];
    }
    ans=solve(0,code.length()-1);
    for (int i=1;i<=n;i++){
        bool tmp;
        cin>>tmp;
        if (tmp){
            ans!=ans;
        }
    }
    int q;
    cin>>q;
    for (int i=1;i<=q;i++){
        int tmp1;
        cin>>tmp1;
        if (!vis[tmp1]){
            cout<<!ans<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}