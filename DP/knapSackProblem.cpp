#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        if (wt[i] <= W)
            v.push_back(make_pair(val[i], wt[i]));
    }
    sort(v.begin(), v.end(), comp);
    int sum = 0;
    for (int i = 0; i < v.size() && W > 0; i++)
    {
        W -= v[i].second;
        if (W >= 0)
            sum += v[i].first;
        else
            break;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n, W;
    cin >> n >> W;
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << knapSack(W, wt, val, n) << endl;
    return 0;
}
