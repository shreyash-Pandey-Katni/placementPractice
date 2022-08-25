#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int knapSackDP(int W, int wt[], int val[], int n)
{
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = W; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    return dp[W];
}