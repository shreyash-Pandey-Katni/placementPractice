#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int solve(int arr[], int i, int j, vector<vector<int>> &memo)
{
    if (i >= j)
    {
        return 0;
    }
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }
    
    int minVal = INT_MAX;
    for (int k = i; k < j; k++)
    {
        minVal = min(solve(arr, i, k, memo)+ solve(arr, k+1, j, memo)+arr[i-1]*arr[k]*arr[j], minVal);
    }
    memo[i][j] = minVal;
    return minVal;
}

int matrixMultiplicationDP(int N, int arr[]){
    vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i>=j){
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = dp[0].size() - 1; j > i; j--)
        {
            int minVal = INT_MAX;
            for (int k = i; k < j; k++)
            {
                minVal = min(minVal, dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
            dp[i][j] = minVal;            
        }
        
    }
  return dp[N][N];
}

int matrixMultiplicationMemoization(int N, int arr[])
{
    vector<vector<int>>memo(N+1, vector<int>(N+1, -1));
    return solve(arr, 1, N - 1, memo);
}

int main()
{
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};

    int result = matrixMultiplicationDP(N, arr);

    cout << "Minimum number of multiplications required: " << result << endl;

    return 0;
}
