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

int matrixMultiplicationMemoization(int N, int arr[])
{
    vector<vector<int>>memo(N+1, vector<int>(N+1, -1));
    return solve(arr, 1, N - 1, memo);
}

int main()
{
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};

    int result = matrixMultiplicationMemoization(N, arr);

    cout << "Minimum number of multiplications required: " << result << endl;

    return 0;
}
