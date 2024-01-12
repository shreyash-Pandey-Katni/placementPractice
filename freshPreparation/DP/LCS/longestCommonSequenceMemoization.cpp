#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcsMemoization(string X, string Y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (dp[n][m] != -1)
        return dp[n][m];
    if (X[n - 1] == Y[m - 1])
    {
        dp[n][m] = 1 + lcsMemoization(X, Y, n - 1, m - 1, dp); 
        return dp[n][m];
    }
    else{
        dp[n][m] = max(lcsMemoization(X, Y, n - 1, m, dp), lcsMemoization(X, Y, n, m - 1, dp));
        return dp[n][m];
    }
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    int n = X.size();
    int m = Y.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << "Length of LCS is " << lcsMemoization(X, Y, n, m, dp) << endl;

    return 0;
}