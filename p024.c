#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* left, char* right)
{
	char temp = *left;
	*left = *right;
	*right = temp;
}

int compare (const void * a, const void * b)
{
  return ( *(char*)a - *(char*)b );
}

void PrintSortedPermutations(char* inStr, int n)
{
	// Re-implementation of algorithm described here:
	// http://w...content-available-to-author-only...s.org/lexicographic-permutations-of-string/
	int strSize = strlen(inStr);
	// 0. Ensure input container is sorted
	qsort(inStr, strSize, sizeof(char), compare);
	
	int count = 1;
	int largerPermFound = 1;
	do {
		// 1. Print permutation if it's the nth one
        if (count==n) {
        	printf("the %d lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9 is %s\n", n, inStr);
        }
		// 2. Find rightmost char that is smaller than char to its right
		int i;
        for (i = strSize - 2; i >= 0 && inStr[i] >= inStr[i+1]; --i){}
        
        // if we couldn't find one, we're finished, else we can swap somewhere
        if (i > -1)
        {
        	// 3 find character at index j such that 
        	// inStr[j] = min(inStr[k]) && inStr[k] > inStr[i] for all k > i
        	int j = i+1;
        	int k;
        	for(k=j; k<strSize && inStr[k]; ++k)
        	{
        		if (inStr[k] > inStr[i] && inStr[k] < inStr[j])
    				j = k;
        	}
        	
        	// 3. Swap chars at i and j
        	swap(&inStr[i], &inStr[j]);
        	
        	// 4. Sort string to the right of i
        	qsort(inStr+i+1, strSize-i-1, sizeof(char), compare);
        }
        else
        {
        	largerPermFound = 0;
        }
        count = count + 1;
	} while(largerPermFound);
}

int main(void) {
	char str[] = "0123456789";
	
	PrintSortedPermutations(str,1000000);
	return 0;
}

