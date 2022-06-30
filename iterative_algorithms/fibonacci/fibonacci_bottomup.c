#include <stdio.h>
#include <stdlib.h>

/*
	Algorithm that calculates the n-th number of the Fibonacci sequence
	in an iterative way with the bottom-up technique using an array.
	Prerequisites: n > 0 integer
	Postrequisites: returns the n-th number of the Fibonacci sequence
	This algorithm as time and space complexity Theta(n).
 */
int fib_bottomup(int n) 
{
	if(n <= 2)
		return 1;
	else {
		int fib[n];
		fib[0] = 1;
		fib[1] = 1;
		for(int i = 2; i < n; i++)
			fib[i] = fib[i-1] + fib[i-2];
		return fib[n-1];
	}

}

int main(int argc, char const *argv[])
{
	int num = 10;

	printf("The %i-th number of the Fibonacci sequence is %i\n", num, fib_bottomup(num));
	return 0;
}