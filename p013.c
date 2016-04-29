/*

Problem 14

Work out the first ten digits of the sum of the following one-hundred
50-digit numbers.

(see ascii file p013numbers.txt)

*/

#include <stdio.h>

int main(int argc, char *argv[]) {


  char sum[101];
  for (int i=0; i<100; i++) {
    sum[i] = '0';
  }
  sum[100] = '\0';
  int carry = 0;
  int digit = 0;
  char int50[100];
  FILE *fid = fopen("p013numbers.txt","r");
  for (int i=0; i<100; i++) {
    printf("%s\n", sum);
    for (int i50=0; i50<50; i50++) {
      int50[i50] = '0';
    }
    fscanf(fid, "%s", (char *)&(int50[50]));

    for (int isum=99; isum>=0; isum--) {
      digit = (sum[isum]-'0') + (int50[isum]-'0') + carry;
      if (digit > 9) {
	carry = 1;
	digit = digit - 10;
      }
      else {
	carry = 0;
      }
      sum[isum] = digit + '0';
    }

    printf("%s\n", int50);
    printf("\n");
  }
  fclose(fid);
  printf("%s\n", sum);
  return 0;

}
