#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 8

void *pthread_hello(void* t) {
	long tid;
	tid = (long) t;

	printf("Hello World from pthread = %ld\n", tid);
	return NULL;
}

int pthread_test() {
	pthread_t threads[NUM_THREADS];
	void *status[NUM_THREADS];
	int rc;
	long t;

	for(t = 0; t < NUM_THREADS; t++) {
		printf("Creating thread %ld\n",t);
		rc = pthread_create(&threads[t], NULL, pthread_hello, (void *) t);
		if (rc) {
			printf("Create thread faild with %d errno\n", rc);
			exit(-1);
		}
	}

	for(t = 0; t < NUM_THREADS; t++) {
		rc = pthread_join(threads[t], &status[t]);
		if (rc) {
			printf("pthread_join() failed with %d errno\n",rc);
			exit(-1);
		}
	}

	return 0;
}


int main(int argc, char *argv[]) {

	pthread_test();

	return EXIT_SUCCESS;
}
