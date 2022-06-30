#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	Linear Search of element a in the array A from index i to index j,
	in an iterative way.
	Preconditions: A[i...j] is an integer array, a is an integer
	Postconditions: returns k = min {k' in i...j | A[k'] = a} if it exists,
					-1 otherwise
*/
int linear_search_it(int A[], int i, int j, int a)
{
	int k = i;
	while(k <= j && A[k] != a)
		k = k+1;

	if(k <= j) // A[k] == a
		return k;
	else // for all h in i...j, A[h] != a
		return -1;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int i = 0, length = 5;
	int A[length];

	printf("Creating array...\n");
	for(i = 1; i <= length; i++) {
		A[i-1] = rand()%(i*length);
		printf("- %i\n", A[i-1]);
	}

	//int a = 0;
	//int a = A[0];
	int a = A[i-2];

	int index = linear_search_it(A,0,length-1,a);

	printf("\n\nSearching element %i in array A: %s (index %i)\n", a, (index!=-1 ? "found": "not found"), index);

	return 0;
}