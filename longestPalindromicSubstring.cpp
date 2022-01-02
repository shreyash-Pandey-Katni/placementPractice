#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string longestPalindrome(string s)
{
    int n = s.size();
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    int start = 0, end = 0;
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
            end = i + 1;
            max_len = 2;
        }
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            int k = i + j - 1;
            string sub = s.substr(j, i);
            if (dp[j + 1][k - 1] && s[j] == s[k])
            {
                dp[i][k] = true;
                if (i > max_len)
                {
                    max_len = i;
                    start = j;
                    end = k;
                }
            }
        }
    }
    return s.substr(start, end - start + 1);
}
int main(int argc, char const *argv[])
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}
