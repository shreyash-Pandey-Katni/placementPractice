#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Calculates the minimum number of coins required to make a given value using a given set of coins.
 * 
 * @param coins The set of coins available.
 * @param M The number of coins in the set.
 * @param V The target value.
 * @return The minimum number of coins required to make the target value. Returns -1 if it is not possible to make the target value.
 */
int minCoins(vector<int> &coins, int M, int V)
{
    vector<vector<int>>dp(M+1, vector<int>(V+1, 0));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(j==0)
            dp[i][j] = 0;
            else if(i==0)
            dp[i][j] = INT_MAX-1;
        }
        
    }

    for (int i = 1; i < dp[0].size(); i++)
    {
        if(i%coins[0] == 0){
            dp[1][i] = i/coins[0];
        } else {
            dp[1][i] = INT_MAX - 1;
        }
    }
    

    for (int i = 2; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i][j-coins[i-1]] +1, dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }
    if(dp[M][V] != INT_MAX-1)
    return dp[M][V];
    return -1;    
}

int main() {
    vector<int> coins = {1, 2, 3};
    int M = coins.size();
    int V = 4;

    int result = minCoins(coins, M, V);
    if (result != -1) {
        cout << "Minimum number of coins required is " << result << endl;
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}