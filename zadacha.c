#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	char array[3];

	int fp = open("zadacha.c", O_RDONLY);

	while(1) {

		int f = read(fp,array,1);
			
			write(STDOUT_FILENO,&array,f);
		
			if(f == 0) {
				break;
			}
		}

	close(fp);

	return 0;
}