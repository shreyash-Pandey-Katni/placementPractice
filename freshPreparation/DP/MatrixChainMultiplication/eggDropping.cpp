#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <climits>

using namespace std;

int solve(int egg, int floor)
{
    if (egg == 1 || floor == 0 || floor == 1)
        return floor;
    int ans = INT_MAX;
    for (int k = 1; k <= floor; k++)
    {
        int temp = 1 + max(solve(egg - 1, k - 1), solve(egg, floor - k));
        ans = min(ans, temp);
    }
    return ans;
}

int solveR(int egg, int floor, vector<vector<int>> &dp)
{
    if (egg == 1 || floor == 0 || floor == 1)
    {
        return floor;
    }
    if (dp[egg][floor] != -1)
    {
        return dp[egg][floor];
    }
    int ans = INT_MAX;
    for (int k = 1; k <= floor; k++)
    {
        int bottom = 0;
        int top = 0;
        if (dp[egg - 1][k - 1] != -1)
            bottom = dp[egg - 1][k - 1];
        else
            bottom = solveR(egg - 1, k - 1, dp);
        if (dp[egg][floor - k] != -1)
            top = dp[egg][floor - k];
        else
            top = solveR(egg, floor - k, dp);
        ans = min(ans, 1 + max(top, bottom));
    }
    dp[egg][floor] = ans;
    return ans;
}

int solveDp(int egg, int floor)
{
    vector<vector<int>> dp(egg + 1, vector<int>(floor + 1, -1));
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for (int j = 1; j < dp[0].size(); j++)
    {
        dp[1][j] = j;
    }

    for (int i = 2; i < dp.size(); i++)
    {
        for (int j = 2; j < dp[0].size(); j++)
        {
            int low = 1, high = j;
            while (low < high)
            {
                int mid = (low + high) / 2;
                int left = dp[i - 1][mid - 1];
                int right = dp[i][j - mid];
                if (left < right)
                    low = mid + 1;
                else
                    high = mid;
            }
            dp[i][j] = 1 + max(dp[i - 1][low - 1], dp[i][j - low]);
        }
    }
    return dp[egg][floor];
}

int main()
{
    // Test Case 1
    int egg = 100;
    int floor = 10000;

    vector<vector<int>> dp(egg + 1, vector<int>(floor + 1, -1));

    auto start = std::chrono::high_resolution_clock::now(); // Start the timer

    int result1 = solveDp(egg, floor);
    cout << "Test Case 1: " << result1 << endl;

    auto end = std::chrono::high_resolution_clock::now();                               // Stop the timer
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the duration in microseconds

    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
