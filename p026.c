/*

Problem 26

A unit fraction contains 1 in the numerator. The decimal representation of
the unit fractions with denominators 2 to 10 are given:

1/2		= 	0.5
1/3		= 	0.(3)
1/4		= 	0.25
1/5		= 	0.2
1/6		= 	0.1(6)
1/7		= 	0.(142857)
1/8		= 	0.125
1/9		= 	0.(1)
1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring
cycle in its decimal fraction part.

*/

// gcc -o p026 p026.c

#include <stdio.h>


int cycle_len(int x) {

	if (x==0) {
		return 0; // invalid fraction
	}
	int position = 1;
	int dividend = 1;
	int remainder;
	int R[10000] = {0}; // what remainders have we seen so far
	while (1) {
		remainder = dividend % x;
		if (remainder == 0) {
			return 0; // divides equally, thus no repeating cycle
		}
		if (R[remainder] > 0) { // we have seen this remainder before! a cycle!
			return position - R[remainder]; // length of the cycle
		}
		R[remainder] = position; // we haven't seen this remainder, store its position
		position = position + 1;
		dividend = remainder * 10;
	}

}

int main(int argc, char *argv[]) {

	int d = 0;
	int c = 0;
	int c_longest = 0;
	for (int i=0; i<1000; i++) {
		c = cycle_len(i);
		if (c > c_longest) {
			d = i;
			c_longest = c;
		}
	}

	printf("the value of d<1000 for which 1/d contains the longest recurring cycle is %d\n", d);

	return 0;
}










