#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Calculates the maximum value that can be obtained by selecting items from two vectors A and B,
 * subject to a given capacity C, using dynamic programming.
 *
 * @param A The vector containing the values of the items.
 * @param B The vector containing the weights of the items.
 * @param C The maximum capacity of the knapsack.
 * @return The maximum value that can be obtained.
 */


int knapSackDP(vector<int> &A, vector<int> &B, int C)
{
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, -1));
    for (int i = 0; i < dp.size(); i++)
        for (int j = 0; j < dp[0].size(); j++)
            if (i == 0 || j == 0)
                dp[i][j] = 0;
    for (int i = 1; i < dp.size(); i++)
        for (int j = 1; j < dp[0].size(); j++)
            {
                // if(dp[i][j] != -1){
                //     continue;
                // }
                if (B[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else if(B[i-1] <=j){
                    dp[i][j] = max(dp[i-1][j-B[i-1]]+A[i-1], dp[i-1][j]);
                }
            }
    return dp[A.size()][C];
}

int main() {
    vector<int> A = {359, 963, 465, 706, 146, 282, 828, 962, 492};
    vector<int> B = {96, 43, 28, 37, 92, 5, 3, 54, 93};
    int C = 383;

    cout << "Maximum value that can be obtained is " << knapSackDP(A, B, C) << endl;

    return 0;
}