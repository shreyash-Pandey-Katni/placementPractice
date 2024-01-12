#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int shortestCommonSupersequenceLength(string X, string Y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    string lcs = "";
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = dp.size() - 1, j = dp[0].size() - 1;
    while (i > 0 || j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }

    return X.size() + Y.size() - lcs.size();
}



int main(int argc, char const *argv[])
{
    string X = "a";
    string Y = "bkjll";
    cout << shortestCommonSupersequenceLength(X, Y, X.size(), Y.size()) << endl;
    return 0;
}
