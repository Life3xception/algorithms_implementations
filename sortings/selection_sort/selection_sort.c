#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Selection Sort on the array A
	Preconditions: length = length(A)
	Postconditions: A[0...n-1] is ordered
*/
void selection_sort(int A[], int length)
{
	int i = 0, k = 0, j = 0;

	for(i = 0; i < length-1; i++) {
		k = i;
		for(j = i+1; j < length; j++) {
			if(A[k] > A[j])
				k = j;
		}

		// switch A[i] with A[k]
		int aux = A[i];
		A[i] = A[k];
		A[k] = aux;
	}
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0, length = 10;
	int A[length];

	// selection sort is a sorting algorithm, so it wants a disordered array as input
	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	printf("\nSorting array...\n\n");

	selection_sort(A,length);

	printf("Printing ordered array:\n");
	for(i = 0; i < length; i++) {
		printf("- %i\n", A[i]);
	}

	return 0;
}