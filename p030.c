/*

Problem 30

Surprisingly there are only three numbers that can be written
as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of
fifth powers of their digits.

*/

// gcc p030.c -o p030

#include <stdio.h>

int main(int argc, char *argv[]) {

	// work out max number of digits to search
	// 9^5 + 9^5 + 9^5 + 9^5 = 236196 : 4 digits -> 6 digits
	// 9^5 + 9^5 + 9^5 + 9^5 + 9^5 = 295245 : 5 digits -> 6 digits
	// 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 = 354294 : 6 digits -> 6 digits
	// 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 + 9^5 = 413343 : 7 digits -> 6 digits
	// so max we should search is 6 digits (up to 354294)

	char s[7];
	int total;
	int p = 0;
	int d;
	for (int i=2; i<=354294; i++) {
		sprintf(s,"%06d", i); // print to string with leading zeros
		total = 0;
		for (int j=0; j<6; j++) {
			d = s[j]-'0';  // each digit
			d = d*d*d*d*d; // take to the 5th power
			total = total + d;
		}
		if (total == i) {
			printf("%06d\n", i);
			p = p + i;
		}
	}

	printf("sum of all the numbers that can be written\nas the sum of fifth powers of their digits\nis %d\n", p);

	return 0;
}










