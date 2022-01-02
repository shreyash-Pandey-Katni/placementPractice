#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
unordered_map<ll,ll> dp;
int tribonacci(int n){
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (dp.find(n) != dp.end())
        return dp[n];
    dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    return dp[n];
}