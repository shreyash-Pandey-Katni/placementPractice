#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long int
unordered_map<ll, ll> dp;
int helper(vector<int> &cost, int n)
{
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return min(cost[0], 0);
    if (dp.find(n) != dp.end())
        return dp[n];
    dp[n] = min(helper(cost, n - 1) + cost[n - 1], helper(cost, n - 2) + cost[n - 2]);
    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost)
{
    return helper(cost, cost.size());
    if (cost.size() == 0)
        return 0;
    if (cost.size() == 1)
        return cost[0];
    if (cost.size() == 2)
        return min(cost[0], cost[1]);
    return helper(cost, cost.size() + 1);
}

int main(int argc, char const *argv[])
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost) << endl;
    return 0;
}
