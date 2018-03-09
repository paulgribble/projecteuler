/*

Problem 22

Using names.txt (right click and 'Save Link/Target As...'),
a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out
the alphabetical value for each name, multiply this value by
its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical
order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
is the 938th name in the list. So, COLIN would obtain
a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

*/

// gcc -o p022 p022.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	// read in the names into a big array

	char names[6000][32];
	for (int i=0; i<6000; i++) {
		for (int j=0; j<32; j++) {
			names[i][j] = '\0';
		}
	}

	char c;

	FILE *fid = fopen("p022_names.txt", "r");

	int i_name = 0;
	int i_char = 0;
	while (fscanf(fid, "%c", &c) != EOF) {
		if (c=='"') {
			i_char = 0;
		}
		else if (c==',') {
			i_name += 1;
		}
		else {
			names[i_name][i_char] = c;
			i_char += 1;
		}
	}

	fclose(fid);

	int n = i_name+1;

	// sort the array of names

	qsort(names, n, 32, strcmp);

	// for (int i=0; i<n; i++) {
	// 	printf("%s\n", names[i]);
	// }

	// work out alphabetic values, and multiply by alphabetic position, and sum

	long int s = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<strlen(names[i]); j++) {
			 s = s + (i+1)*(names[i][j]-'A'+1);
		}
	}

	printf("the total of all the name scores is %ld\n", s);

  return 0;
}










