#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
unordered_map<ll,ll> dp;
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(dp.find(n) != dp.end())
        return dp[n];
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}