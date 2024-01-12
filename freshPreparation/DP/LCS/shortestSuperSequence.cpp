#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string shortestCommonSupersequence(string X, string Y, int n, int m)
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
    string sss = "";
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
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            sss.push_back(X[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                sss.push_back(X[i - 1]);
                i--;
            }
            else
            {
                sss.push_back(Y[j - 1]);
                j--;
            }
        }
    }
    if (i > 0)
    {
        string temp = string(X.begin(), X.begin() + i);
        reverse(temp.begin(), temp.end());
        sss.append(temp);
    }

    if (j > 0)
    {
        string temp = string(Y.begin(), Y.begin() + j);
        reverse(temp.begin(), temp.end());
        sss.append(temp);
    }

    reverse(sss.begin(), sss.end());
    return sss;
}

int main()
{
    // Test inputs
    string X = "abac";
    string Y = "cab";
    int n = X.length();
    int m = Y.length();

    // Call the function
    string result = shortestCommonSupersequence(X, Y, n, m);

    // Print the result
    cout << "Shortest common supersequence: " << result << endl;

    return 0;
}
