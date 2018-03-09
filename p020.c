/*

Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

*/

// gcc -o p020 p020.c -lgmp

#include <stdio.h>
#include <gmp.h>
#include <string.h>

#define N 100

int main(int argc, char *argv[]) {

  mpz_t n, result;

  mpz_init(result);
  mpz_set_ui(result, N);

  long int nn = N;
  
  for (int i=1; i<N; i++) {
    mpz_mul_ui(result, result, nn-i);
  }
 
  char cresult[1024];

  gmp_sprintf(cresult, "%Zd\n", result);

  printf("%s", cresult);

  int sn = strlen(cresult) - 1; // exclude newline character
  int s = 0;
  for (int i=0; i<sn; i++) {
    s = s + (cresult[i]-'0');
  }
  printf("the sum of the digits in the number %d! is %d\n", N, s);
  
  mpz_clear(result);

  return 0;
}


