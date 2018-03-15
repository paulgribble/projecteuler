/*

Problem 27

Considering quadratics of the form:

n^2 + an + b, where |a|<1000 and |b|<1000

where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the
quadratic expression that produces the maximum number of
primes for consecutive values of n, starting with n=0.

*/

// gcc p027.c -o p027

#include <stdio.h>
#include <stdlib.h>

#define MAXPRIMES 2000000

int *primes;

int isprime(long int x) {
	if ( (x>=0) && (primes[x] != -1)) { // have we determined primeness for this x yet?
		return primes[x];
	}
	else {
		if (x == 2) {
			primes[x] = 1;
			return 1;
		}
		else if (x < 2) {
//  	primes[x] = 0;
			return 0;
		}
		else if ((x % 2) == 0) {
			primes[x] = 0;
			return 0;
		}
		int i;
		for (i=3; (i*i)<=x; i+=2) {
			if ((x % i) == 0) {
				primes[x] = 0;
				return 0;
			}
		}
		primes[x] = 1;
		return 1;
	}
}

int numprimes(int a, int b) { // counts number of consecutive primes
	int p = 0;
	for (int n=0; n<=abs(a); n++) {
		if (isprime(n*n + a*n + b)) {
			p = p + 1;
		}
		else {
			return p;
		}
	}
	return p;
}

int main(int argc, char *argv[]) {

	primes = malloc(sizeof(int)*MAXPRIMES);
	for (int i=0; i<MAXPRIMES; i++) {
		primes[i] = -1; // not checked yet
	}

	int maxp = 0;
	int maxa, maxb, np;
	for (int a=-999; a<1000; a++) {
		for (int b=-1000; b<=1000; b++) {
			np = numprimes(a,b);
			if (np>maxp) {
				printf("maxp=%4d a=%4d b=%4d\n", np, a, b);
				maxp = np;
				maxa = a;
				maxb = b;
			}
		}
	}

	printf("The product of the coefficients %d and %d is %d\n", maxa, maxb, maxa*maxb);

	free(primes);
	return 0;
}










