/*

Problem 28

Starting with the number 1 and moving to the right in a clockwise
direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
formed in the same way?

*/

// gcc p028.c -o p028

#include <stdio.h>

#define N 1001

int main(int argc, char *argv[]) {

	// by hand, look at pattern for N=3, N=5, N=7
	// for i=3:2:N {i^2 + (i^2 - (i-1)) + (i^2 - 2*(i-1)) + (i^2 - 3*(i-1)) + 1}

	long int s = 0;
	int inc;
	for (int i=3; i<=N; i=i+2) {
		for (int j=0; j<=3; j++) {
			inc = ((i*i) - j*(i-1));
//			printf("%d: %d: %d\n", i, j, inc);
			s = s + inc;
		}
	}
	s = s + 1;

	printf("the sum of the numbers on the diagonal of N=%d is %ld\n", N, s);

	return 0;
}










