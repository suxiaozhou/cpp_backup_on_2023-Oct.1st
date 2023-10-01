#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>p[100010];
int a[100010];

void solve(int x, int v) { // 目前访问 x 结点，这波遍历访问的最大编号是 v
    a[x]=v; // x 可以到最大的点设置为 v
    for (int i=0;i<p[x].size();i++) // 遍历 x 引出的边
        if (a[p[x][i]]==0) // 如果目标节点没有被访问过
            solve(p[x][i],v); // 继续递归，DFS 遍历目标节点
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        p[v].push_back(u); // 建立 v 到 u 的边
    }
    for (int i = n; i > 0; i--)
        if (a[i]==0) // 如果点 i 没有被访问过
            solve(i,i);// 从 i 开始遍历，最大值为 i
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
}


