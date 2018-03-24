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

// gcc p092.c -o p092

#include <stdio.h>
#include <string.h>

#define N 10000000

int square_digits(int x) {
	char s[48];
	sprintf(s, "%d", x);
	int result = 0;
	int slen = strlen(s);
	int d;
	for (int i=0; i<slen; i++) {
		d = s[i]-'0';
		result = result + (d*d);
	}
	return result;
}

int arrives89(int x) {
	int i=x;
	int found1or89 = 0;
	while (found1or89==0) {
		i = square_digits(i);
		if ((i==1) || (i==89)) {
			found1or89 = 1;
		}
	}
	if (i==89) {
		return 1;
	}
	else {
		return 0;
	}
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



