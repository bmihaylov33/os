#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void* function(void *arg) {
	printf("Hi\n");
	int * p = malloc(sizeof(int));
	*p = 4;
	return p;
}



int main () {
	printf("Hello world!\n");
	
	pthread_t a;
	pthread_t* gosho = &a;
	int pa = 0;
	int *p = &pa;
	void *pv = 0;
	void **ppv = &pv;

	pthread_create(gosho, NULL, function, NULL);
	pthread_join(a ,ppv);
	int *q = pv;
	printf("%d\n", *q);
	return 0;
}