#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

vector<int> getRow(int rowIndex)
{
    vector<int> res;
    res.push_back(1);
    if (rowIndex == 0)
        return res;
    res.push_back(1);
    for (int i = 2; i <= rowIndex; i++)
    {
        vector<int> temp = {1, 1};
        for (int j = 1; j < i; j++)
        {
            temp.insert(temp.begin() + j, (res[j] + res[j - 1])%mod);
        }
        res = temp;
    }
    return res;
}

int nCrModp(int n, int r)
{
    if (r == 0)
        return 1;
    if (n == r || r == 1)
        return n;
    vector<int> dp = getRow(n);
    return dp[r];

    // your code here
}
int main(int argc, char const *argv[])
{
    int n, r;
    cin >> n >> r;
    cout << nCrModp(n, r) << endl;
    return 0;
}
