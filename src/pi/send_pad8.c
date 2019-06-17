#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>


int main() {
	FILE* fp = fopen("/dev/hidg0", "wb");
	if (fp == NULL) {
		printf("/dev/hidg0 open failed");
		return 0;
	}
	int c=0;
	char keyon[8] = {};
	char keyoff[8] = {};
	bool flag=false;
	int sleep_sec = 0.1 * 1000;
	FILE* sendfp = fopen("/dev/stdin", "rb");
	if (sendfp == NULL) {
		printf("sendfp open failed");
		return 0;
	}
	char senddata[4];
	void sendkey() {
		fwrite(keyon, 1, 8, fp);
		fflush(fp);
		usleep(1000000/48);
	}
	keyon[2] = 8;
	keyon[3] = 0x80;
	keyon[4] = 0x80;
	keyon[5] = 0x80;
	keyon[6] = 0x80;
	sendkey();
	sendkey();
	while(true) {
		memset(senddata, 0, 1);
		int fff=fread(senddata, 1, 1, sendfp);
		if (fff < 1) break;
		printf("%d", fff);
		flag=!flag;
		char code = senddata[0];
		keyon[0] = code; // button ABXY + LR + ZL/R
		keyon[2] = c;    // HAT Switch
		sendkey();
		c += 1;
		if (c >= 8) c = 0;
	}
	keyon[0] = 0;
	keyon[2] = 8;
	sendkey();
	return 0;
}
