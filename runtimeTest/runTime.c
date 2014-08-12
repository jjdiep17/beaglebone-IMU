#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int mymillis()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec) * 1000000 + (tv.tv_usec);
}

int main() {


	int loop = 0;
	int sample = 0;
	int delta = 0;
	int oldSample = 0;

	FILE *fp;
	char *mode = "w";
	fp = fopen("sample_PRU.txt", mode);

	if (fp == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", "sample_PRU.txt");
		exit(1);
	}

	int startInt  = mymillis();

	while(loop < 1000) {
		sample = mymillis()-startInt;
		fprintf(fp, "Read time: %d\t", sample);
		delta = sample - oldSample;
		fprintf(fp, "Delta: %d\n", delta);
		oldSample = sample;
		loop++;
	}

	fclose(fp);
	return 0;
}
