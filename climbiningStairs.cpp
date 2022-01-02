#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
unordered_map<ll,ll> dp;
int climbStairs(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(dp.find(n) != dp.end())
        return dp[n];
    dp[n] = climbStairs(n-1) + climbStairs(n-2);
    return dp[n];
}