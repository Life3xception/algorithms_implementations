#include <stdio.h>
#include <stdlib.h>

/*
	Algorithm that calculates the n-th number of the Fibonacci sequence
	using the memoization technique.
	Prerequisites: n > 0 integer, memo is an array with length(memo) > n and all values 
					in it are -1.
	Postrequisites: returns the n-th number of the Fibonacci sequence
	This algorithm as time complexity Theta(n).
 */
int fib_memoization(int n, int memo[]) 
{
	if(memo[n] != -1)
		return memo[n];

	int f;
	if(n <= 2)
		f = 1;
	else
		f = fib_memoization(n-1,memo) + fib_memoization(n-2,memo);

	memo[n] = f;
	return f;
}

int main(int argc, char const *argv[])
{
	int num = 10;
	int memo[num+1];

	// initializing the memo array
	for(int i = 0; i <= num; i++)
		memo[i] = -1;

	printf("The %i-th number of the Fibonacci sequence is %i\n", num, fib_memoization(num,memo));
	return 0;
}