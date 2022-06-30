#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definition of the type returned by the algorithms
typedef struct { 
	int min;
	int max;
} min_max_couple;

/*
	Algorithm that returns min and max in the subarray [p...q]
	from the array A
	Prerequisites: 0 <= p <= q, q < length(A)
 */
min_max_couple di_min_max(int A[], int p, int q)
{
	min_max_couple ris;

	if(p == q) {
		ris.min = A[p];
		ris.max = A[p];
		return ris;
	}

	if(p == q-1) {
		if(A[p] < A[q]) {
			ris.min = A[p];
			ris.max = A[q];
		}
		else {
			ris.min = A[q];
			ris.max = A[p];
		}
		return ris;
	}

	int r = (p+q)/2;
	min_max_couple ris_1 = di_min_max(A,p,r);
	min_max_couple ris_2 = di_min_max(A,r+1,q);
	ris.min = (ris_1.min < ris_2.min ? ris_1.min : ris_2.min);
	ris.max = (ris_1.max > ris_2.max ? ris_1.max : ris_2.max);
	return ris;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0, length = 10, start = length/2, end = length-1;
	int A[length];

	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	printf("Searching min and max in [%i...%i]\n", start, end);
	min_max_couple result = di_min_max(A,start,end);
	printf("Min: %i\n", result.min);
	printf("Max: %i\n", result.max);
	return 0;
}