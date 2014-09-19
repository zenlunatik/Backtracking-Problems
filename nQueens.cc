#include <iostream>
#include <stdlib.h>

using namespace std;

void
processSolution(int* ar, int k, int n)
{
    cout<<"{";
    for (int ii = 0 ; ii < k; ii++) {
        cout<<"("<<ii<<"," <<ar[ii]<<") ";
    }
    cout<<"}"<<endl;
}
        
void
getCandidates(int* ar, int k , int n, int *candidates, int &ncandidates)
{
    ncandidates = 0;
    for (int ii = 0; ii < n; ii++) {
        bool threat = false;
        for (int jj = 0; jj < k; jj++) {
            // Column threat
            if (ii == ar[jj]) {
                threat = true;
                break;
            }

            // Diagonal threat
            if (abs(k-jj) == abs(ii-ar[jj])) {
                threat = true;
                break;
            }

        }

        if (!threat) {
            candidates[ncandidates++] = ii;
        }
    }
}

void
backtrack(int* ar, int k, int n)
{
    if (k == n) {
        processSolution(ar, k, n);
    } else {
        int candidates[8];
        int ncandidates = 0;
        getCandidates(ar, k , n, candidates, ncandidates);
        for (int ii = 0; ii < ncandidates; ii++) {
            ar[k] = candidates[ii];
            backtrack(ar, k+1, n);
        }
    }
}

int main()
{
    int n = 8;
    int ar[8];
    backtrack(ar, 0, n);
}
