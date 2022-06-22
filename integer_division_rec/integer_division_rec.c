#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int q; // quotient
	int r; // reminder
} integer_division_result;

/*
	Integer Division between two numbers, a and b.
	Preconditions: a >= 0, b > 0
	Postconditions: returns q,r so that a = b*q + r
		and 0 <= r < b
*/
integer_division_result div_rec(int a, int b) 
{
	integer_division_result res;
	
	if(a < b) {
		res.q = 0;
		res.r = a;
	}
	else {
		res = div_rec(a-b, b);
		res.q = res.q + 1;
	}

	return res;
}

int main()
{
	int a = 16;
	int b = 4;
	integer_division_result result;

	result = div_rec(a,b);

	printf("Integer Division of %i / %i as quotient %i and reminder %i\n", a, b, result.q, result.r);
}