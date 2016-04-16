/*

Problem 10

Summation of primes


The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.  

*/

#include <stdio.h>

int isprime(long int x) {
  if (x == 2) {
    return 1;
  }
  else if (x < 2) {
    return 0;
  }
  else if ((x % 2) == 0) {
    return 0;
  }
  int i;
  for (i=3; (i*i)<=x; i+=2) {
    if ((x % i) == 0) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {

  long int sum = 2;
  long int p = 2;
  long int i = 3;
  while (i < 2000000) {
    if (isprime(i)==1) {
      p = i;
      sum = sum + p;
    }
    i = i + 2;
  }
  printf("the sum of all primes less than 2 million is %ld\n", sum);
  
  return 0;

}
