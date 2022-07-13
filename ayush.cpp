#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void dfs(pair<int, int> v, int i, int count, int &ans)
{
    if (v.first == v.second)
    {
        ans = min(ans, count + v.first);
        return;
    }
    if (v.first == 0 || v.second == 0)
        return;
    if (ans == INT_MAX)
    {
        count++;
        dfs({v.first - 1, v.second - 1}, i + 1, count, ans);
        if (v.first > v.second)
            dfs({v.first, v.second * 2}, i + 1, count, ans);
        else
            dfs({v.first * 2, v.second}, i + 1, count, ans);
        count--;
    }
}

int numberOfStepsRequired(pair<int, int> num)
{
    int steps = 0;
    int count = 0;
    int ans = INT_MAX;
    dfs(num, 0, count, ans);
    if (ans == INT_MAX)
        return -1;
    return ans;
}
int main(int argc, char const *argv[])
{
    int t = 0;
    int n = 0;
    cin >> t;
    while (t--)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        cout << numberOfStepsRequired(temp) << endl;
    }

    return 0;
}
