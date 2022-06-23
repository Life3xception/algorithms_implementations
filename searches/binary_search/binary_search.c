#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
	Binary Search of element x in the array A
	Preconditions: A[i...j] is already ordered
	Postconditions: true if x in A[i...j], false otherwise
*/
int binary_search_rec(int x, int A[], int i, int j)
{
	if(i > j) // A[i...j] is empty
		return 0;
	else {
		int m = floor((i+j)/2);
		if(x == A[m])
			return 1;
		else {
			if(x < A[m])
				return binary_search_rec(x,A,i,m-1);
			else // x > A[m]
				return binary_search_rec(x,A,m+1,j);
		}
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int lenght = 5;
	int A[lenght];

	// binary search wants an ordered array as input
	printf("Creating array...\n");
	for(int i = 0; i < lenght; i++) {
		A[i] = i*lenght;
		printf("- %i\n", A[i]);
	}

	//int x = 10; // found
	//int x = 5; // found
	int x = 7; // not found

	printf("\n\nSearching element %i in array A: %s\n", x, (binary_search_rec(x,A,0,lenght)==1 ? "found": "not found"));

	return 0;
}