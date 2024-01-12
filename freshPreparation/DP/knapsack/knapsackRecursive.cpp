#include <iostream>
#include <vector>
using namespace std;

/**
 * Calculates the maximum value that can be obtained by selecting items from the given weights and values,
 * such that the total weight does not exceed the given capacity.
 *
 * @param wt An array of weights of the items.
 * @param value An array of values of the items.
 * @param w The capacity of the knapsack.
 * @param n The number of items.
 * @param dp A 2D vector used for memoization to store previously calculated results.
 * @return The maximum value that can be obtained.
 */
int knapSackRecursive(int wt[], int value[], int w, int n, vector<vector<int>> dp){
    if(n==0 || w == 0)
    return 0;
    if (dp[n][w] != -1){
        return dp[n][w];
    }
    if (wt[n-1]>w)
    return dp[n][w]=knapSackRecursive(wt, value, w, n-1, dp);
    else
    return dp[n][w]=max(knapSackRecursive(wt, value, w-wt[n-1], n-1, dp) + value[n-1], knapSackRecursive(wt, value, w, n-1, dp));
}


int main() {
    int wt[] = {96, 43, 28, 37, 92, 5, 3, 54, 93};
    int value[] = {359, 963, 465, 706, 146, 282, 828, 962, 492};
    int w = 383;
    int n = sizeof(value) / sizeof(value[0]);
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout << "Maximum value that can be obtained is " << knapSackRecursive(wt, value, w, n, dp) << endl;
    return 0;
}