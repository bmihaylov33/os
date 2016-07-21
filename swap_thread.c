#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

int binari = 0;

void* function (void* arg) {
	int *p = arg;
	
	int i = 0;
	while (i < 10) {
		if (binari == *p) {
			printf("Hello, I'm thread: %d \n", *p);
			pthread_mutex_lock(&mutex);
			binari++;
			pthread_mutex_unlock(&mutex);
			i++;
			if (binari == 2)
				binari = 0; 
		}	
	}
}

int main() {
	pthread_mutex_init(&mutex, NULL);
	int a = 0;
	int b = 1;
	int *pa = &a;
	int *pb = &b;
	pthread_t thread1;
	pthread_t thread2;
	pthread_create(&thread1, NULL, function, pa);
	pthread_create(&thread2, NULL, function, pb);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutex);

	return 0;
}