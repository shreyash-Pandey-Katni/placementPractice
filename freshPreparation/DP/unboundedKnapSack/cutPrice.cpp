#include <iostream>
#include <vector>
using namespace std;

/**
 * Calculates the maximum value that can be obtained by cutting a rod of length 'n' into smaller pieces.
 * 
 * @param price An array of prices for different lengths of rod.
 * @param n The length of the rod.
 * @return The maximum value that can be obtained.
 */
int cutRod(int price[], int n){
    int capacity = n;
    vector<int> length(n, 1);
    for (int i = 0; i < n; i++)
    {
        length[i] = i+1;
    }
    vector<vector<int>>dp(n+1, vector<int>(capacity+1, -1));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(length[i-1] <= j){
                dp[i][j] = max(dp[i][j-length[i-1]] + price[i-1], dp[i-1][j]);
            }
            else
            dp[i][j] = dp[i-1][j];
        }
        
    }
    return dp[n][capacity];
}

int main() {
    int N = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << "Maximum obtainable value is " << cutRod(price, N) << endl;

    return 0;
}