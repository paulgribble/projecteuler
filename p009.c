/*

Problem 9

Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c,
for which,

a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which
a + b + c = 1000. Find the product abc.

*/

#include <stdio.h>

int solution(int a, int b, int c) {
  if (((a + b + c) == 1000) & (((a*a)+(b*b)) == (c*c)) & (a<b) & (b<c)) {
    return 1;
  }
  else {
    return 0;
  }
}

int main(int argc, char *argv[]) {

  int solved = 0;
  for (int a=1; ((a<500) & (solved==0)); a++) {
    for (int b=1; ((b<500) & (solved==0)); b++) {
      for (int c=1; ((c<500) & (solved==0)); c++) {
	if (solution(a,b,c)==1) {
	  solved = 1;
	  printf("(a,b,c) = (%d,%d,%d), a+b+c=%d, a*b*c=%d\n", a, b, c, a+b+c, a*b*c);
	  }
      }
    }
  }
  
  return 0;

}
