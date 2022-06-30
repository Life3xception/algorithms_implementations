#include <stdio.h>
#include <stdlib.h>

/*
	Algorithm that calculates the n-th number of the Fibonacci sequence
	Prerequisites: n > 0 integer
	Postrequisites: returns the n-th number of the Fibonacci sequence
	This algorithm as time complexity Omega(2^n) (at least exponential).
 */
int fib_rec(int n) 
{
	if(n <= 2)
		return 1;
	else
		return fib_rec(n-1) + fib_rec(n-2);
}

int main(int argc, char const *argv[])
{
	int num = 10;
	printf("The %i-th number of the Fibonacci sequence is %i\n", num, fib_rec(num));
	return 0;
}