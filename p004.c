/*

Problem 4

Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome
made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.  

*/

#include <stdio.h>
#include <string.h>

int is_palindrome(int x) {

  char s1[32];
  char s2[32];
  sprintf(s1, "%d", x);
  sprintf(s2, "%d", x);
  int s1len = strlen(s1);
  for (int i=0; i<s1len; i++) {
    s2[i] = s1[s1len-i-1];
  }
  s2[s1len] = '\0';
  if (strcmp(s1,s2)==0) {
    return 1;
  }
  else {
    return 0;
  }
}

int main(int argc, char *argv[]) {

  int largest = 0;
  for (int i=100; i<999; i++) {
    for (int j=100; j<999; j++) {
      int x = i*j;
      if (is_palindrome(x)) {
	if (x > largest) {
	  largest = x;
	}
      }
    }
  }
  printf("largest palindrome made from the product of two 3-digit numbers is %d\n", largest);
  
  return 0;

}
