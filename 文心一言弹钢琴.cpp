#include <windows.h>

int main() {
	// 设置播放频率和持续时间
	int frequency1 = 261; // C4
	int duration1 = 1000;
	int frequency2 = 294; // D4
	int duration2 = 1000;
	int frequency3 = 330; // E4
	int duration3 = 1000;
	int frequency4 = 349; // F#4
	int duration4 = 1000;
	int frequency5 = 392; // G#4
	int duration5 = 1000;
	int frequency6 = 440; // A4
	int duration6 = 1000;
	int frequency7 = 466; // B4
	int duration7 = 1000;
	int frequency8 = 523; // C#5
	int duration8 = 1000;
	int frequency9 = 554; // D5
	int duration9 = 1000;
	int frequency10 = 587; // E5
	int duration10 = 1000;
	int frequency11 = 659; // F#5
	int duration11 = 1000;
	int frequency12 = 744; // G#5
	int duration12 = 1000;
	int frequency13 = 880; // A5
	int duration13 = 1000;
	int frequency14 = 988; // B5
	int duration14 = 1000;

	// 播放音乐
	Beep(frequency1, duration1);
	Beep(frequency2, duration2);
	Beep(frequency3, duration3);
	Beep(frequency4, duration4);
	Beep(frequency5, duration5);
	Beep(frequency6, duration6);
	Beep(frequency7, duration7);
	Beep(frequency8, duration8);
	Beep(frequency9, duration9);
	Beep(frequency10, duration10);
	Beep(frequency11, duration11);
	Beep(frequency12, duration12);
	Beep(frequency13, duration13);
	Beep(frequency14, duration14);

	return 0;
}