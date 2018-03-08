/*

Problem 15

Starting in the top left corner of a 2×2 grid, and only being able
to move to the right and down, there are exactly 6 routes to the
bottom right corner.

How many such routes are there through a 20×20 grid?

*/

// gcc -o p015 p015.c

#include <stdio.h>

#define GRIDSIZE 21

long int grid[GRIDSIZE][GRIDSIZE]; // for memoization

long int path(int gx, int gy) {

  if (grid[gx][gy] > 0) {
    return grid[gx][gy];
  }

  long int n;

  if ((gx==0) && (gy==0)) {
    n = 1;
  }
  else {
    n = 0;
    if (gx > 0) {
      n = n + path(gx-1, gy);
    }
    if (gy > 0) {
      n = n + path(gx, gy-1);
    }
  }
  grid[gx][gy] = n;
  return n;
}

int main(){

  for (int i=0; i<GRIDSIZE; i++) {
    for (int j=0; j<GRIDSIZE; j++) {
      grid[i][j] = 0;
    }
  }

  long int result = path(GRIDSIZE-1, GRIDSIZE-1);
  printf("for gridsize %dx%d there are %ld paths\n", GRIDSIZE-1, GRIDSIZE-1, result);

  return 0;

}
