#include <bits/stdc++.h>
using namespace std;
string s;
int n, m, tree_len = 0;
bool vab[100010];

struct tree {
	int l, r, value;
} trees[1000010];

struct msg {
	int value, pos;
};

bool solve2(string st) {
	int tmp1;
	for (int i = st.length() - 1; i >= 0; i--) {
		tmp1 += pow(10, i) * (st[i] - '0');
	}
	return tmp1;
}

msg MSG(int value, int pos) {
	msg tmp_msg;
	tmp_msg.value = value;
	tmp_msg.pos = pos;
	return tmp_msg;
}

msg solve(string st) {
	stack <msg> stack_;
	int l = 0;
	bool va[100010];
	for (int i = 0; i < st.length(); i++) {
		if (st[i] == 'x') {
			int tmp1 = i;
			while (st[i] != ' ') {
				i++;
			}
			string stmp = st;
			stmp.substr(tmp1 + 1, i - tmp1 - 1);
			stack_.push(MSG(solve2(stmp), ++tree_len));
		}
		if (st[i] == '&') {
			msg tmp3, tmp2;
			tmp3 = stack_.top();
			stack_.pop();
			tmp2 = stack_.top();
			stack_.pop();
			++tree_len;
			trees[tree_len].l = tmp3.pos;
			trees[tree_len].r = tmp2.pos;
			trees[tree_len].value = 2;
			stack_.push(MSG(tmp3.value && tmp2.value, tree_len));
		}
		if (st[i] == '|') {
			msg tmp3, tmp2;
			tmp3 = stack_.top();
			stack_.pop();
			tmp2 = stack_.top();
			stack_.pop();
			++tree_len;
			trees[tree_len].l = tmp3.pos;
			trees[tree_len].r = tmp2.pos;
			trees[tree_len].value = 3;
			stack_.push(MSG(tmp3.value || tmp2.value, tree_len));
		}
		if (st[i] == '!') {
			msg tmp3;
			tmp3 = stack_.top();
			stack_.pop();
			++tree_len;
			trees[tree_len].l = tmp3.pos;
			trees[tree_len].value = 4;
			stack_.push(MSG(!tmp3.value, tree_len));
		}
	}
	return stack_.top();
}

void in_order(int x) {
	if (trees[x].l)
		in_order(trees[x].l);
	cout << trees[x].value << " ";
	if (trees[x].r)
		in_order(trees[x].r);
}

int main() {
	getline(cin, s);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> vab[i];
	}
	msg trees_msg = solve(s);
	in_order(trees_msg.pos);
	/*
	cin>>m;
	for (int i=1;i<=m;i++){
		int tmp;
		cin>>tmp;
		vab[tmp]=!vab[tmp];
		cout<<solve(s)<<endl;
		vab[tmp]=!vab[tmp];
	}
	*/
	return 0;
}

