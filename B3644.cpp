#include <bits/stdc++.h>
using namespace std;
int n, ind[110];
vector <int> link[10010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		while (1) {
			cin >> tmp;
			if (tmp == 0) {
				break;
			}
			link[i].push_back(tmp);
			ind[tmp]++;
		}
	}
	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < link[now].size(); i++) {
			int tmp = link[now][i];
			ind[tmp]--;
			if (ind[tmp] == 0) {
				q.push(tmp);
			}
		}
	}
	cout << endl;
	return 0;
}

