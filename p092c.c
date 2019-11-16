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

// gcc -O3 p092c.c -o p092c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000000
#define NC 9999

int arrives89(int x, int *chainer) {
	int ss, digit;
	int chain[99]; for (int i=0; i<99; i++) { chain[i] = 0; }
	int n_chain = 0;
	while (x!=1 & x!=89) {
		ss = 0;
		while (x > 0) {
			digit = x % 10;
			ss = ss + digit*digit;
			x = (x-digit)/10;
		}
		x = ss;
		chain[n_chain] = x;
		n_chain = n_chain + 1;
		if (chainer[x] == 89) {
			for (int i=0; i<n_chain; i++) { chainer[chain[i]] = 89; }
			return 1;
		}
		else if (chainer[x] == 1) {
			for (int i=0; i<n_chain; i++) { chainer[chain[i]] = 1; }
			return 0;
		}
	}
	if (x==89) {
		for (int i=0; i<n_chain; i++) { chainer[chain[i]] = 89; }
		return 1;
	}
	else {
		for (int i=0; i<n_chain; i++) { chainer[chain[i]] = 1; }
		return 0;
	}
}

int main(int argc, char *argv[]) {

	int *chainer = malloc(NC * sizeof(int));
	for (int i=0; i<NC; i++) { chainer[i] = 0; }

	int count = 0;
	for (int i=2; i<N; i++) {
		if (arrives89(i, chainer)==1) {
			count = count + 1;
		}
	}

	printf("%d starting numbers below 10 million arrive at 89\n", count);

	free(chainer);
	return 0;
}


