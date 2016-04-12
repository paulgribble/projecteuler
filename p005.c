/*

Problem 5

Smallest multiple

2520 is the smallest number that can be divided by each of the numbers
from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all
of the numbers from 1 to 20?

*/

#include <stdio.h>

int is_divisible(int x) {
  int pass = 1;
  int i = 1;
  while (pass & (i <= 20)) {
    if ((x % i) > 0) {
      pass = 0;
    }
    i = i + 1;
  }
  return pass;
}

int main(int argc, char *argv[]) {

  int answer = 1;
  while (is_divisible(answer)==0) {
    answer = answer + 1;
  }
  printf("the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is %d\n", answer);
    
  return 0;

}
