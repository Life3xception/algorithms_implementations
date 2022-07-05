#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Bubble Sort on the array A
	Preconditions: n = length(A)
	Postconditions: A[0...n-1] is ordered
*/
void bubble_sort(int A[], int n)
{
	int i,j;

	for(i = 0; i <= n-2; i++) {
		for(j = n-1; j >= i+1; j = j-1) {
			if(A[j] < A[j-1]) {
				// switch A[j] with A[j-1]
				int aux = A[j];
				A[j] = A[j-1];
				A[j-1] = aux;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0, length = 10;
	int A[length];
	//int A[] = {10,9,8,7,6,5,4,3,2,1};
	//int A[] = {1,2,3,4,5,6,7,8,9,10};

	// bubble sort is a sorting algorithm, so it wants a disordered array as input
	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	printf("\nSorting array...\n\n");

	bubble_sort(A,length);

	printf("Printing ordered array:\n");
	for(i = 0; i < length; i++) {
		printf("- %i\n", A[i]);
	}

	return 0;
}