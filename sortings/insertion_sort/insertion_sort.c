#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Insertion Sort on the array A
	Preconditions: length = length(A)
	Postconditions: A[0...n-1] is ordered
*/
void insertion_sort(int A[], int length)
{
	int i = 0;

	for(i = 1; i < length; i++) {
		int j = i;
		while(j > 0 && A[j-1]>A[j]) {
			// switch A[j-1] with A[j]
			int aux = A[j];
			A[j] = A[j-1];
			A[j-1] = aux;

			j = j - 1;
		}
	}
}


int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0, length = 10;
	int A[length];

	// insertion sort is a sorting algorithm, so it wants a disordered array as input
	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	printf("\nSorting array...\n\n");

	insertion_sort(A,length);

	printf("Printing ordered array:\n");
	for(i = 0; i < length; i++) {
		printf("- %i\n", A[i]);
	}

	return 0;
}