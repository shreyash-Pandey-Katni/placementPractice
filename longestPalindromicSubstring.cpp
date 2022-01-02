#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
string longestPalindrome(string s)
{
    if (isPalindrome(s))
        return s;
    int n = s.size();
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    int start = 0;
    int max_len = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i + 1] == s[i])
        {
            dp[i][i + 1] = true;
            start = i;
            // end = i + 1;
            max_len = 2;
        }
    }
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n - k + 1; ++i)
        {
            int j = i + k - 1;
            string sub = s.substr(i, j);
            if (dp[i + 1][j - 1] && s[i] == s[j])
            {
                dp[i][j] = true;
                if (k > max_len)
                {
                    max_len = k;
                    start = i;
                    // end = k;
                }
            }
        }
    }
    return s.substr(start, max_len);
}
int main(int argc, char const *argv[])
{
    string s = "bacabab";
    cout << longestPalindrome(s) << endl;
    return 0;
}
