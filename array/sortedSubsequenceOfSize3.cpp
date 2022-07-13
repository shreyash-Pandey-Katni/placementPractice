#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <set>
using namespace std;

vector<int> find3Numbers(vector<int> arr, int N)
{
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }
    vector<int> res;
    int i = 0;
    auto it = s.end();
    while (it != s.begin() && i < 3)
    {
        it--;
        if (it == s.begin())
        {
            res.push_back(*it);
            break;
        }
        if (s.find(*it - 1) != s.end())
        {
            res.push_back(*it);
        }
        i++;
    }
    if (res.size() != 3)
    {
        return vector<int>();
    }
    sort(res.begin(), res.end());
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> res = find3Numbers(arr, n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
