#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

long long countWays(int n){
    long long dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cout<<countWays(n)<<endl;
    return 0;
}
