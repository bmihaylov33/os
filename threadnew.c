#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 10

pthread_mutex_t m;
int count = 1;

void* hello(void* thread_id) {
	int *tid = thread_id;
	int i = 0;

	while(i < 10) {
		if(count == *tid) {
			printf("Hello from thread N%d\n", *tid);
			pthread_mutex_lock(&m);
			count++;
			pthread_mutex_unlock(&m);
			i++;
			
			if(count == 11) count = 1;
			
		}
	} 
	pthread_exit(NULL);

}

int main(int argc, char *argv[]) {
	pthread_t threads[NUM_THREADS];
	pthread_mutex_init(&m, NULL);
	int a = 1;
	int *pa = &a;

		for(i = 0; i < NUM_THREADS; i++) {
			pthread_create(&threads[0], NULL, hello, pa);
			a++;
			pthread_join(threads[t], NULL);
			if(a == NUM_THREADS) break;
	}
	pthread_mutex_destroy(&m);

	return 0;
}