#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// vector<vector<int>> dp;
int eggDrop(int n, int k)
{
    int dp[n + 1][k + 1];
    if (k == 1 || k == 0 || n == 1)
    {
        return k;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        dp[1][i] = i;
        // dp[0][i] = i;
    }

    int min = INT_MAX, res;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x <= j; x++)
            {
                res = 1 + max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j])
                {
                    dp[i][j] = res;
                }
            }
        }
    }
    return dp[n][k];
}
