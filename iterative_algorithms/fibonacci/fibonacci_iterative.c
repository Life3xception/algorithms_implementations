#include <stdio.h>
#include <stdlib.h>

/*
	Algorithm that calculates the n-th number of the Fibonacci sequence
	in an iterative way with the bottom-up technique but using variables
	instead of an array.
	Prerequisites: n > 0 integer
	Postrequisites: returns the n-th number of the Fibonacci sequence
	This algorithm as time complexity Theta(n) but space complexity Theta(1).
 */
int fib_it(int n) 
{
	if(n <= 2)
		return 1;
	else {
		int fib1 = 1, fib2 = 1, tmp;
		for(int i = 3; i <= n; i++) {
			tmp = fib1 + fib2;
			fib2 = fib1;
			fib1 = tmp;
		}
		return fib1;
	}
}

int main(int argc, char const *argv[])
{
	int num = 10;

	printf("The %i-th number of the Fibonacci sequence is %i\n", num, fib_it(num));
	return 0;
}