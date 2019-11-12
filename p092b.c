/*

Problem 92

A number chain is created by continuously adding the square of the digits
in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless
loop. What is most amazing is that EVERY starting number will eventually
arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?

*/

// gcc -O3 p092b.c -o p092b

#include <stdio.h>
#include <string.h>

#define N 10000000

int arrives89(int x) {
	int ss, digit;
	while (x!=1 & x!=89) {
		ss = 0;
		while (x > 0) {
			digit = x % 10;
			ss = ss + digit*digit;
			x = (x-digit)/10;
		}
		x = ss;
	}
	if (x==89) return 1;
	else return 0;
}

int main(int argc, char *argv[]) {

	int count = 0;
	for (int i=2; i<N; i++) {
		if (arrives89(i)==1) {
			count = count + 1;
		}
	}

	printf("%d starting numbers below 10 million arrive at 89\n", count);

	return 0;
}


