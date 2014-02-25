#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int openmp_test() {
	int nthreads, tid;

	#pragma omp parallel private(nthreads, tid)
	{
		/* Obtain Thread number */
		tid = omp_get_thread_num();
		printf("Hello World from OMP thread = %d\n", tid);
		if (tid == 0) {
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
		}
	} /* All threads join master thread and disband */

	return 0;
}

int main(int argc, char *argv[]) {

	openmp_test();

	return EXIT_SUCCESS;
}
