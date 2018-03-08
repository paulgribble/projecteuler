/*

Problem 16

215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/

// gcc -o p016 p016.c -lgmp

#include <gmp.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

  mpz_t result,base;

  mpz_init(result);
  mpz_init(base);

  mpz_set_ui(base,2);

  unsigned long int exponent = 1000;

  mpz_pow_ui(result, base, exponent);
 
  char cresult[1024];

  gmp_sprintf(cresult, "%Zd\n", result);

//  printf("%s", cresult);

  int n = strlen(cresult) - 1; // exclude newline character
  int s = 0;
  for (int i=0; i<n; i++) {
    s = s + (cresult[i]-'0');
  }
  printf("the sum of the digits of the number 2^1000 is %d\n", s);

  mpz_clear(base);
  mpz_clear(result);

  return 0;

}
