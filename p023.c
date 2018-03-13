/*

Problem 23

A perfect number is a number for which the sum of its proper divisors
is exactly equal to the number. For example, the sum of the proper
divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28
is a perfect number.

A number n is called deficient if the sum of its proper divisors is
less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the
smallest number that can be written as the sum of two abundant numbers
is 24. By mathematical analysis, it can be shown that all integers
greater than 28123 can be written as the sum of two abundant
numbers. However, this upper limit cannot be reduced any further by
analysis even though it is known that the greatest number that cannot
be expressed as the sum of two abundant numbers is less than this
limit.

Find the sum of all the positive integers which cannot be written as
the sum of two abundant numbers.

*/

// gcc -o p023 p023.c -lm

#include <stdio.h>
#include <math.h>

int is_abundant(int n) {

  int s = 0;
  for (int i=1; i<n; i++) {
    if ((n % i) == 0) {
      s = s + i;
    }
  }
  return (s>n);
}

int main(int argc, char *argv[]) {

  int A[28123]; // list of abundant numbers
  int An = 0;   // number of items in the list
  for (int i=1; i<=28123; i++) {
    if (is_abundant(i)) {
	A[An] = i;
	An = An + 1;
      }
  }

  int AA[28123]; // integers between 1 and 28123
  for (int i=1; i<28123; i++) {
    AA[i] = i;
  }
  for (int i=0; i<An; i++) {
    for (int j=0; j<An; j++) {
      if (A[i]+A[j] <= 28123) {
	AA[A[i]+A[j]] = 0;
      }
    }
  }

  int s = 0;
  for (int i=0; i<28123; i++) {
    s = s + AA[i];
  }
  
  printf("the sum of all the positive integers which cannot be written as the sum of two abundant numbers is %d\n", s);

  return 0;
}










