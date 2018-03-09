/*

Problem 21

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which
divide evenly into n).

If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and
each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

// gcc -o p021 p021.c

#include <stdio.h>

#define N 10000

int sum_divisors(int n) {
	int s = 0;
	for (int i=1; i<n; i++) {
		if (n%i == 0) {
			s = s + i;
		}
	}
	return s;
}

int main(int argc, char *argv[]) {

	int a = 0;
	int s1 = 0;
	int s2 = 0;
	for (int i=1; i<N; i++) {
		s1 = sum_divisors(i);
		s2 = sum_divisors(s1);
		if ((s2==i) && (i != s1)) {
			a = a + s1;
		}
	}

	printf("the sum of all the amicable numbers under %d is %d\n", N, a);

  return 0;
}


