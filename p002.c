/*

  Problem 2

  Even Fibonacci numbers

  Each new term in the Fibonacci sequence is generated by adding the
  previous two terms. By starting with 1 and 2, the first 10 terms
  will be:

  1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

  By considering the terms in the Fibonacci sequence whose values do
  not exceed four million, find the sum of the even-valued terms.
  
*/

#include <stdio.h>

int main(int argc, char *argv[]) {

  long int fm2 = 1;
  long int fm1 = 2;
  long int f = fm1 + fm2;
  long int sum = 2;
  while (f < 4000000) {
    if ((f % 2) == 0) {
      sum = sum + f;
    }
    fm2 = fm1;
    fm1 = f;
    f = fm1 + fm2;
  }

  printf("the sum of the even-valued terms is %ld\n", sum);
  
  return 0;

}
