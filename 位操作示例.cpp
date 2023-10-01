#include <bits/stdc++.h>
using namespace std;
//made by sxz on Aug 2023
const long long maxn = 800000000;
char set_[maxn];//a primary set_ of database.

bool read_bit(long long pos) {
	long long ltmp = maxn * 8;
	if (pos < 0 || pos > ltmp) {
		cerr << "readERR:\"pos\" out. pos=" << pos << endl;
		return 0;
	}
	//int a_piece_of_all_set(1 byte size)
	int piece = set_[pos / 8];
	int tmp = pow(2, pos % 8 + 1);
	//bool the_bit
	bool t_bit = piece %  tmp - piece % (tmp / 2);
	return t_bit;
}

bool write_bit(long long pos, bool bit) {
	long long ltmp = maxn * 8;
	if (pos < 0 || pos > ltmp) {
		cerr << "readERR:\"pos\" out. pos=" << pos << endl;
		return 0;
	}
	//int a_piece_of_all_set(1 byte size)
	int piece = set_[pos / 8];
	int tmp = pow(2, pos % 8 + 1);
	//bool before_change_bit
	bool bf_ch_bi = piece %  tmp - piece % (tmp / 2);
	if (bf_ch_bi) { //if at first the bit is 1,we need to change it to 0.
		piece -= pow(2, pos % 8);
	}
	piece += bit * pow(2, pos % 8);
	set_[pos / 8] = piece;
	return 1;
}

int main() {
	long long Q, p, b;
	//################################################
	/*
	//常规操作
	string cmd;
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> cmd;
		if (cmd == "w") {
			cin >> p >> b;
			write_bit(p, b);
		} else if (cmd == "r") {
			cin >> p;
			cout << read_bit(p) << endl;
		}
	}
	*/
	//################################################
	/*
	//超大数据量去重
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> p;
		if (!read_bit(p)) {
			cout << p << " ";
		}
		write_bit(p, 1);
	}
	*/
	//################################################
	/*
	//极端数据测试
	read_bit(10000000000);
	read_bit(-10000000000);
	*/
	//################################################
	return 0;
}

