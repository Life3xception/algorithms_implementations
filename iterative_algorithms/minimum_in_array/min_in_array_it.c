#include <stdio.h>
#include <stdlib.h>

/*
	Finds the minimum value in the array A starting from index i
	Preconditions: 0 < n = length(A), 0 <= i <= n-1
	Postconditions: returns the minimum in A[i...n-1]
*/
int min_it(int A[], int i, int n) {
	int min = A[i++];
	while(i < n) {
		if(A[i] < min)
			min = A[i];
		i++;
	}
	return min;
}

int main(int argc, char const *argv[])
{
	//int A[] = {1, 2, 3, 4, 5, 6};
	int A[] = {6, 5, 4, 3, 2, 1};
	int length = 6;
	int index = 0;

	printf("Printing array A:\n");

	for(int i = 0; i < length; i++)
		printf("\t- %i\n", A[i]);

	printf("\nMinimum element in the array starting from index %i is: %i\n", index, min_it(A,index,length));

	return 0;
}