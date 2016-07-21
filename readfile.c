#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	
	char arr[3];
	int i;

	int fp = open("readfile.c", O_RDONLY);

	while(1) {
		int f = read(fp,arr,1);
		write(STDOUT_FILENO, &arr, fp);
		
		if(f == 0){
			break;
		}
	}
	return 0;
}