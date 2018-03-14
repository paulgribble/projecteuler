/*

Problem 25

The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?


*/

// gcc -o p025 p025.c -lm -lgmp

#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <string.h>

#define NN 1000

int main(int argc, char *argv[]) {

	mpz_t Fnm2;
	mpz_t Fnm1;
	mpz_t Fn;
 	mpz_init(Fnm2);
 	mpz_init(Fnm1);
 	mpz_init(Fn);
	mpz_set_ui(Fnm2, 1);
	mpz_set_ui(Fnm1, 1);
	mpz_add(Fn, Fnm2, Fnm1);
	int i = 3;
	char cresult[1024];
	gmp_sprintf(cresult, "%Zd\n", Fn);
	int ndigits = strlen(cresult)-1;
	while (ndigits < NN) {
		i = i + 1;
		mpz_set(Fnm2, Fnm1);
		mpz_set(Fnm1, Fn);
		mpz_add(Fn, Fnm2, Fnm1);
		gmp_sprintf(cresult, "%Zd\n", Fn);
		ndigits = strlen(cresult)-1;
	}
//	gmp_printf("%8d : %d : %s \n", i, ndigits, cresult);
	printf("the index of the first term in the Fibonacci sequence to contain %d digits is %d\n", NN, i);

  return 0;
}










