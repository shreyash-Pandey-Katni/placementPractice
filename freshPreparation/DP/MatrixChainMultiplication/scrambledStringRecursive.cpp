#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_map>

using namespace std;

bool solveRecursive(string A, string B, unordered_map<string, bool> &dp)
{
    int n = A.size();
    if (A.compare(B) == 0 && A.size() != 0)
        return true;
    if (A.size() == 0)
        return false;
    if (dp.find(A + ":" + B) != dp.end())
        return dp[A + ":" + B];
    for (int i = 1; i < A.size(); i++)
    {
        bool leftCase1 = false;
        bool rightCase1 = false;
        bool leftCase2 = false;
        bool rightCase2 = false;

        if (dp.find(A.substr(0, i) + ":" + B.substr(n - i, i)) != dp.end())
            leftCase1 = dp[A.substr(0, i) + ":" + B.substr(n - i, i)];
        else
            leftCase1 = solveRecursive(A.substr(0, i), B.substr(n - i, i), dp);

        if (dp.find(A.substr(i, n - i) + ":" + B.substr(0, n - i)) != dp.end())
            rightCase1 = dp[A.substr(i, n - i) + ":" + B.substr(0, n - i)];
        else
            rightCase1 = solveRecursive(A.substr(i, n - i), B.substr(0, n - i), dp);

        if (dp.find(A.substr(0, i) + ":" + B.substr(0, i)) != dp.end())
            leftCase2 = dp[A.substr(0, i) + ":" + B.substr(0, i)];
        else
            leftCase2 = solveRecursive(A.substr(0, i), B.substr(0, i), dp);

        if (dp.find(A.substr(i, n - i) + ":" + B.substr(i, n - i)) != dp.end())
            rightCase2 = dp[A.substr(i, n - i) + ":" + B.substr(i, n - i)];
        else
            rightCase2 = solveRecursive(A.substr(i, n - i), B.substr(i, n - i), dp);

        if ((leftCase1 && rightCase1) || (leftCase2 && rightCase2))
        {
            dp[A + ":" + B] = true;
            return true;
        }
    }
    return dp[A + ":" + B] = false;
}

bool solve(string A, string B, vector<vector<vector<int>>> &dp)
{
    int n = A.size();
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            for (int j = 0; j <= n - len; j++)
            {
                if (len == 1)
                {
                    dp[i][j][len] = (A[i] == B[j]);
                }
                else
                {
                    for (int k = 1; k < len && dp[i][j][len] == false; k++)
                    {
                        dp[i][j][len] = (dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                                        (dp[i][j + len - k][k] && dp[i + k][j][len - k]);
                    }
                }
            }
        }
    }
    return dp[0][0][n];
}

int isScramble(const string A, const string B)
{
    int n = A.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, false)));
    unordered_map<string, bool> dpMap = {};

    return solve(A, B, dp);
    return solveRecursive(A, B, dpMap);
}

int main()
{
    string A = "abbbcbaaccacaacc";
    string B = "acaaaccabcabcbcb";

    auto start = chrono::high_resolution_clock::now(); // Start measuring time

    int result = isScramble(A, B);

    auto end = chrono::high_resolution_clock::now();                          // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Calculate duration in microseconds

    cout << "IsScramble: " << result << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl; // Print the time taken

    return 0;
}
