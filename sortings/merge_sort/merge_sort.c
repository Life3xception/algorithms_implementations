#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
	Algorithm that merges the element of two subarrays into a 
	new array
	Prerequisites: A is an array, first <= middle <= last < length(A)
					A[first...middle] and A[middle+1...last] are ordered
	Postrequisites: A[first...last] is ordered
*/
void merge(int A[], int first, int last, int middle)
{
	int i = first, j = middle+1, k = 0;
	int B[last-first+1]; // defining an auxiliary array to do the ordering

	while(i <= middle && j <= last) {
		if(A[i] <= A[j]) {
			B[k] = A[i];
			i = i+1;
		}
		else {
			B[k] = A[j];
			j = j+1;
		}
		k = k+1;
	}

	if(i <= middle) { // then j > last and A[j...last] is empty
		while(k <= last-first && i <= middle) {
			B[k] = A[i];
			i = i+1;
			k = k+1;
		}
	}
	else { // then i > middle and A[i...middle] is empty
		while(k <= last-first && j <= last) {
			B[k] = A[j];
			j = j+1;
			k = k+1;
		}
	}

	for(k = 0, i = first; k <= last-first && i <= last; k++, i++)
		A[i] = B[k];
}

/*
	Implementation "in place" of the merge sort algorithm
	Prerequisites: A is an array, first <= last < length(A)
	Postrequisites: A is ordered in a non descending order
 */
void merge_sort(int A[], int first, int last)
{
	if(first < last) {
		int middle = floor((first+last)/2);
		merge_sort(A, first, middle);
		merge_sort(A, middle+1, last);
		merge(A, first, last, middle);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0, length = 10;
	int A[length];
	//int A[] = {10,9,8,7,6,5,4,3,2,1};
	//int A[] = {1,3,5,7,9,2,4,6,8,10};

	// merge sort is a sorting algorithm, so it wants a disordered array as input
	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	printf("\nSorting array...\n\n");

	merge_sort(A,0,length-1);

	printf("Printing ordered array:\n");
	for(i = 0; i < length; i++) {
		printf("- %i\n", A[i]);
	}

	return 0;
}