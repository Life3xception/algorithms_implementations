#include <stdio.h>
#include <stdlib.h>

/*
	Finds the minimum value in the array A starting from index i
	Preconditions: 0 < n = length(A), 0 <= i <= n-1
	Postconditions: returns the minimum in A[i...n-1]
*/
int min_rec(int A[], int i, int n) {
	if(i == n-1)
		return A[i]; // only element in A[n-1...n-1]
	else {
		int min = min_rec(A, i+1, n);
		return (min <= A[i] ? min : A[i]);
	}
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

	printf("\nMinimum element in the array starting from index %i is: %i\n", index, min_rec(A,index,length));

	return 0;
}