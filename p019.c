/*

Problem 19

You are given the following information, but you may prefer to do some
research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century
unless it is divisible by 400.

How many Sundays fell on the first of the month during
the twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

// gcc -o p019 p019.c

#include <stdio.h>

int main(int argc, char *argv[]) {

	int M[] = {31,0,31,30,31,30,31,31,30,31,30,31};
	int S = 0;
	int dm;
	int d = 0; // Monday

	for (int y=1900; y<=2000; y++) {
		if ( ((y%4)==0) && ( ((y%100)!=0) || ((y%400)==0) ) ) { // leap year
			M[1] = 29;
		}
		else {
			M[1] = 28;
		}
		for (int m=0; m<12; m++) {
			for (int i=0; i<M[m]; i++) {
				d = (d+1) % 7;
				if ( (d==6) && (i==0) && (y>=1901) )  { // d==6: Sunday
					S = S + 1;
				}
			}
		}
	}

	printf("%d Sundays fell on the first of the month during the twentieth century\n", S);

	return 0;
}


