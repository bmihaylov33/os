#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

int fp1 = open("test.txt", O_RDONLY);
int fp2 = open("test.txt", O_RDONLY);

const int LENGTH = 256;
char line[LENGTH];
int linecount = 0;
	
	while (fgets(line, LENGTH, fp1) != NULL) {
		if (linecount < 10)
			linecount++;
		else {
			fgets(line, LENGTH, fp2);
		}
	}

	if (linecount < 10) {
		printf("less than 10 lines in the file\n");
	return 1;
	}

	while (fgets(line, LENGTH, fp2) != NULL) {
		printf("%s", line);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}
