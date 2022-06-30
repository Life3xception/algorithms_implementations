#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void switch_elements_in_array(int A[], int i, int j)
{
	int aux = A[i];
	A[i] = A[j];
	A[j] = aux;
}

/*
	Partitions the elements in the segment A[start...end] using the first 
	element in the segment as a pivot.
	Prerequisites: 0 <= start <= end, end = length(A)-1
 */
int partition_first_element(int A[], int start, int end) 
{
	int i = start+1, j = end;

	while(i <= j) {
		if(A[i] <= A[start])
			i = i + 1;
		else {
			if(A[j] > A[start])
				j = j - 1;
			else {
				// switch A[i] with A[j]
				switch_elements_in_array(A,i,j);
				i = i + 1;
				j = j - 1;
			}
		}
	}

	switch_elements_in_array(A,start,j);
	return j;
}

/*
	Implementation of the quick sort, sorts element in the array A
	using the algorithm of partition that reorganizes the elements
	using as pivot the first element of the given segment.
	Prerequisites: 0 <= start <= end, end = length(A)-1
*/
void quick_sort(int A[], int start, int end)
{
	if(end > start) {
		int p = partition_first_element(A, start, end); // after partitioning, pivot is at 
											      		// index p in A

		if(p > start)
			quick_sort(A,start,p-1);
		
		if(p < end-1)
			quick_sort(A,p+1,end);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int i = 0, length = 10;
	int A[length];
	//int A[] = {10,9,8,7,6,5,4,3,2,1};
	//int A[] = {1,2,3,4,5,6,7,8,9,10};

	// quick sort is a sorting algorithm, so it wants a disordered array as input
	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	printf("\nSorting array...\n\n");

	quick_sort(A,0,length-1);

	printf("Printing ordered array:\n");
	for(i = 0; i < length; i++) {
		printf("- %i\n", A[i]);
	}

	return 0;
}