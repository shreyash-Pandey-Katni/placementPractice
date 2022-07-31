#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int countVowelStrings(int n)
{
    vector<int> dp(5, 1);
    for (int i = 1; i < n;i++){
        for (int i = 3; i >= 0; i--)
        {
            dp[i] = dp[i] + dp[i + 1];
        }
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += dp[i];
    }
    return sum;
}