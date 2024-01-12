#include <iostream>
#include <vector>
using namespace std;



/**
 * Calculates the maximum value that can be obtained by selecting items from the given values and weights,
 * without any restriction on the number of times an item can be selected, such that the total weight does not exceed the given capacity.
 *
 * @param values The values of the items.
 * @param weights The weights of the items.
 * @param capacity The maximum weight capacity of the knapsack.
 * @return The maximum value that can be obtained.
 */
int unboundedKnapSack(vector<int> values, vector<int> weights, int capacity){
    int n = values.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i==0 || j==0)
            dp[i][j] = 0;
        }
        
    }
    

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(weights[i-1] <= j){
                dp[i][j] = max(dp[i][j-weights[i-1]] + values[i-1], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];    
}

int knapSack(int n, int capacity, int values[], int weights[]){
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, -1));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i==0 || j==0)
            dp[i][j] = 0;
        }
        
    }
    

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(weights[i-1] <= j){
                dp[i][j] = max(dp[i][j-weights[i-1]] + values[i-1], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];    
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // capacity of the knapsack

    cout << "Maximum value that can be obtained is " << unboundedKnapSack(values, weights, W) << endl;
    cout<< "gfg knapsack "<< knapSack(values.size(), W, values.data(), weights.data())<<endl;
    return 0;
}