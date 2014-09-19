#include <iostream>
#include "gtest/gtest.h"

#define GTESTON 1 

using namespace std;

void
allSubsets(int *ar, int k, int n, int &total)
{
    if (k == n) {
#if !GTESTON
        cout<<"{";
        for (int ii = 0; ii < k; ii++) {
            if (ar[ii]) {
                cout<<ii+1;
            }
        }
        cout<<"}";
        cout<<endl;
#endif
        ++total;
    } else {
        int candidates[2] = {0, 1};
        for (int ii = 0; ii < 2; ii++) {
            ar[k] = candidates[ii];
            allSubsets(ar, k+1, n, total); 
        }
    }
}

#if GTESTON
TEST(allSubsetsTest, ZERO) {
    int ar[1];
    int total = 0;
    allSubsets(ar, 0, 0, total);
    EXPECT_EQ(1, total); 
}

TEST(allSubsetsTest, FOUR) {
    int ar[4];
    int total = 0;
    allSubsets(ar, 0, 4, total);
    EXPECT_EQ(16, total); 
}
#endif

int main(int argc, char **argv)
{
#if GTESTON
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#else
    int ar[4];
    int total;
    allSubsets(ar, 0, 4, total);
#endif
}
