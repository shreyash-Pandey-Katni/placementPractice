#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b)
{
    return a[1] > b[1];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(2));
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i][0] = a;
        v[i][1] = b;
        score += v[i][0];
    }
    int requiredScore = k * n - score;
    if (requiredScore <= 0)
    {
        cout << "0";
        return 0;
    }
    sort(v.begin(), v.end(), compare);
    int count = 0;
    for (int i = n - 1; i >= 0 && requiredScore > 0; i--)
    {
        if ((m - v[i][0])>requiredScore){
            count += requiredScore*v[i][1];
            requiredScore = 0;
        }
        else {
        count += (m - v[i][0]) * v[i][1];
        requiredScore -= (m - v[i][0]);
        }
    }
    cout << count;
    return 0;
}