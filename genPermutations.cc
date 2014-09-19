#include <iostream>
#include <stdio.h>
#include "gtest/gtest.h"

#define GTESTON 0

void
processSolution(int* ar, int k)
{
    for (int ii = 0; ii < k; ii++) {
        printf("%d ", ar[ii]);
    }
    printf("\n");
}

void
genCandidates(int* ar, int k, int* candidates, int &ncandidates, int n)
{
    ncandidates = 0;
    for (int ii = 0; ii < n; ii++) {
        bool isCandidate = true;
        for (int jj = 0; jj < k; jj++) {
            if (ar[jj] == ii) {
                isCandidate = false;
                break;
            }
        }
        if (isCandidate) {
            candidates[ncandidates++] = ii;
        }
    }
}

void
genPermutations(int* ar, int k, int n, int &total)
{
    if (k == n) {
#if !GTESTON
        processSolution(ar, k);
#endif
        ++total;
    } else {
        int candidates[n];
        int ncandidates = 0;
        genCandidates(ar, k, candidates, ncandidates, n);
        for (int ii = 0; ii < ncandidates; ii++) {
            ar[k] = candidates[ii];
            genPermutations(ar, k+1, n, total);
        }
    }
}

#if GTESTON
TEST(genPermutaionsTest, ONE) {
    int ar[1];
    int total = 0;
    genPermutations(ar, 0, 1, total);
    EXPECT_EQ(1, total); 
}

TEST(genPermutationsTest, FOUR) {
    int ar[4];
    int total = 0;
    genPermutations(ar, 0, 4, total);
    EXPECT_EQ(24, total); 
}
#endif


int main(int argc, char **argv)
{
#if GTESTON
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    int ar[4];
    int total = 0;
    genPermutations(ar, 0, 4, total);
#endif
}
