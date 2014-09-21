#include <stdio.h>

void
processSolution(int* ar, int n)
{
     for (int ii = 0; ii < n; ii++) {
          if (ar[ii] == 0) {
               printf(" right");
          } else {
               printf(" up");
          }
     }
     printf("\n");
}

void
findCandidates(int* candidates, int& nCandidates, int* ar, int cols, int rows, int k)
{
     int rowsT = 0;
     int colsT = 0;
     for (int ii = 0; ii < k; ii++) {
         (ar[ii] == 0) ? ++colsT : ++rowsT;
     }
     nCandidates = 0;
     if (colsT < cols - 1) {
          candidates[nCandidates++] = 0;
     }
     if (rowsT < rows - 1) {
          candidates[nCandidates++] = 1;
     }
}

void
backtrack(int* ar, int k, int n, int cols, int rows)
{
     if (k == n) {
          processSolution(ar,n);
     } else {
          int candidates[n];
          int nCandidates;
          
          findCandidates(candidates, nCandidates, ar, cols, rows, k);
          for (int ii = 0; ii < nCandidates; ii++) {
               ar[k] = candidates[ii];
               backtrack(ar, k+1, n, cols, rows);
          }
     }
}

int main()
{
     int rows = 5;
     int cols = 5;
     int size = rows + cols - 2;
     int ar[size];
     backtrack(ar, 0, size, cols, rows);
}
