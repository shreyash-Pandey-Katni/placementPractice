#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
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
            temp.insert(temp.begin() + j, res[j] + res[j - 1]);
        }
        res = temp;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> res = getRow(n);
    for (int i = 0; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
