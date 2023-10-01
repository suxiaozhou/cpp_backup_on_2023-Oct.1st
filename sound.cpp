#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define spe 600
#define do1 261.626
#define re1 293.665
#define mi1 329.629
#define fa1 349.228
#define so1 391.995
#define la1 440.000
#define si1 493.883
#define do2 523.251
#define re2 587.330
#define mi2 659.255
#define fa2 698.456
#define so2 783.991
#define la2 880.000
#define si2 987.767
#define lenb 26

double sou[lenb] = {mi2, mi2, mi2, do2, mi2, so2, so1, do2, so1, mi1, la1, si1, si1, la1, so1, mi2, so2, la2, fa2, so2, mi2, do2, re2, si1, do2, so1};
double tim[lenb] = {0.5, 0.5, 0.5, 0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5, 0.5};
int main() {
	for (int i = 1; i <= 2; i++) {
		for (int i = 0; i < lenb; i++) {
			Beep(sou[i], tim[i]*spe);
		}
	}
	return 0;
}

