#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t m; 
int count = 1;

char n;

void* hello(void* thread_id) {
	int *tid = thread_id;
	int i = 0;

	while(i < 10) {

		if(count == *tid) {
			printf("Hello from thread N: %d\n", *tid);	
			
			pthread_mutex_lock(&m);
			count ++;
			pthread_mutex_unlock(&m);
		
			i++;

			if (count == (n+1)) count = 1; 

		}
	}
	
	pthread_exit(NULL);
	
}

int main(int argc, char *argv[]) {
	pthread_mutex_init(&m, NULL);
	unsigned int p;
	int thread = p;

	printf("Enter number of threads: ");
	scanf("%s\n", n);

	pthread_t threads[malloc(sizeof(pthread_t)*thread)];

	int a = 1;
	int i;
	int *pa = &a;

	for(i = 0; i < n; i++) {
	int rc = pthread_create(&threads[i], NULL, hello, pa);
		a++;
		pthread_join(threads[i], NULL);
	}	

	pthread_mutex_destroy(&m);

	// pthread_exit(NULL);
	return 0;
}