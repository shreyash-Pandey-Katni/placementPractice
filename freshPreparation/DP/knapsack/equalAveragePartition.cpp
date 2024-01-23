#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> subsetSumProblem(int values[], int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (values[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - values[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp;
}

vector<vector<int>> path(vector<vector<int>> dp, vector<int> A, int ptrLeft, int ptrRight)
{
    vector<vector<int>> res(2, vector<int>());

    int vertPointer = A.size();

    while (ptrLeft != 0 && vertPointer != 0)
    {
        if (dp[vertPointer][ptrLeft] != dp[vertPointer - 1][ptrLeft])
        {
            res[0].push_back(A[vertPointer - 1]);
            ptrLeft -= A[vertPointer - 1];
            vertPointer--;
        }
        else {
            vertPointer--;
        }
    }
    
    vertPointer = A.size();
    
    while (ptrRight != 0 && vertPointer != 0)
    {
        if (dp[vertPointer][ptrRight] != dp[vertPointer - 1][ptrRight])
        {
            res[0].push_back(A[vertPointer - 1]);
            ptrRight -= A[vertPointer - 1];
            vertPointer--;
        }
        else {
            vertPointer--;
        }
    }

    return res;
}

vector<vector<int>> avgset(vector<int> &A)
{
    int sum = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }
    if (sum % 2 != 0)
        return vector<vector<int>>();
    int targetSum = sum / 2;

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (A[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - A[i - 1]] + 1;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    vector<vector<bool>> possible = subsetSumProblem(A.data(), n, sum);

    int ptrLeft = 1, ptrRight = sum - 1;

    while (ptrLeft < ptrRight)
    {
        if (possible[n][ptrLeft] && possible[n][ptrRight])
        {
            if (ptrRight / dp[n][ptrRight] == ptrLeft / dp[n][ptrLeft] && ptrRight%dp[n][ptrRight] == 0 && ptrLeft%dp[n][ptrLeft] == 0)
            {
                return path(dp, A, ptrLeft, ptrRight);
            }
            else if(ptrRight / dp[n][ptrRight] > ptrLeft / dp[n][ptrLeft])
            ptrLeft++;
            else
            ptrRight--;
        }
        else
        {
            if (possible[n][ptrLeft] == false)
            {
                ptrLeft++;
            }
            if (possible[n][ptrRight] == false)
            {
                ptrRight--;
            }
        }
    }
    return dp;
}

int main()
{
    // Example data
    vector<int> A = {1, 7, 15, 29, 11, 9};

    sort(A.begin(), A.end());

    // Call the avgset function
    vector<vector<int>> result = avgset(A);

    for (int i = 0; i < result[0].size(); i++)
    {
        cout << i << " ";
    }

    cout << endl;
    // Print the result
    for (const auto &subset : result)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
