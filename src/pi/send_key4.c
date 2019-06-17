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
	char senddata[1];
	int cnt=2;
	void sendkey() {
		for(int retry=0; retry<cnt; retry++) {
			fwrite(keyon, 1, 8, fp);
		}
		fwrite(keyoff, 1, 8, fp);
	}
	sendkey();
	while(true) {
		memset(senddata, 0, 1);
		int fff=fread(senddata, 1, 1, sendfp);
		if (fff < 1) break;
		printf("%d", fff);
		flag=!flag;
		char code = senddata[0];
		keyon[0] = 0;
		keyon[2] = 4 + (code >> 4);
		sendkey();
		keyon[0] = 2;
		keyon[2] = 4 + (code & 0xf);
		sendkey();
		c += 1;
		if (c >= 34) c = 0;
		fflush(fp);
	}
	return 0;
}