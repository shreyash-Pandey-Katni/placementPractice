#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long countWays(int n)
{
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1] + dp[n - 2];
    // your code here
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}
