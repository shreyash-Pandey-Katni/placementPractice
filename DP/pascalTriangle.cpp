#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    res.push_back(vector<int>{1});
    if (numRows == 1)
        return res;
    res.push_back(vector<int>{1, 1});
    for (int i = 2; i < numRows; i++)
    {
        vector<int> temp = {1, 1};
        for (int j = 1; j < i; j++)
        {
            temp.insert(temp.begin() + j, res[i - 1][j] + res[i - 1][j - 1]);
        }
        res.push_back(temp);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> res = generate(n);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
