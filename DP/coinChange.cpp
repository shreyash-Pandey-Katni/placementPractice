#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value)
{
    vector<long long> dp(value + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= value; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < numberOfCoins; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[value] == INT_MAX ? -1 : dp[value];
}