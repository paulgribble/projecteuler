/*

Problem 3

Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?  

*/

#include <stdio.h>
#include <math.h>

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
  for (i=3; (i*i)<x; i+=2) {
    if ((x % i) == 0) {
      return 0;
    }
  }
  return 1;
}


int main(int argc, char *argv[]) {

  long int target = 600851475143;

  long int i = ceil(sqrt(target));
  int found = 0;
  
  while (found==0) {
    i = i - 1;
    if (((target % i) == 0) & (isprime(i)))
      {
	found = 1;
      }
  }
  
  printf("largest prime factor of %ld is %ld\n", target, i);
  
  return 0;

}
