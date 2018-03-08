/*

Problem 17

If the numbers 1 to 5 are written out in words:
one, two, three, four, five,
then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive
were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens.

For example, 342 (three hundred and forty-two) contains
23 letters and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is incompliance
with British usage.

*/

// gcc -o p017 p017.c

#include <stdio.h>
#include <string.h>

#define NUM 1000

int single[] = {0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8}; // up to 19
int tens[] = {0,3,6,6,5,5,5,7,6,6}; // up to ninety
int hundred = 7;
int thousand = 8;

int main(int argc, char *argv[]){

  int total = 0;
  for (int i=1; i<=NUM; i++) {
    int S = i % 10; // singles digit
    int T = ((i % 100) - S) / 10; // tens digit
    int H = ((i % 1000) - (T * 10) - S) / 100; // hundreds digit
    if (H > 0) {
      total = total + single[H] + hundred;
      if ((T > 0) || (S > 0)) {
        total = total + 3; // "and"
      }
    }
    if ((T == 0) || (T == 1)) {
      total = total + single[T*10 + S];
    }
    else {
      total = total + tens[T] + single[S];
    }
  }
  if (NUM >= 1000) {
    total = total + single[1] + thousand;
  }

  printf("%d letters are used in words up to %d\n", total, NUM);

  return 0;
}
