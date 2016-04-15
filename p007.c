/*

Problem 7

10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
see that the 6th prime is 13.

What is the 10001st prime number?  

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

  long int p = 3;
  long int np = 2;
  long int i = 3;
  while (np < 10001) {
    i = i + 2;
    if (isprime(i)) {
      p = i;
      np = np + 1;
    }
  }

  printf("the 10001st prime number is %ld\n", p);
  
  return 0;

}
