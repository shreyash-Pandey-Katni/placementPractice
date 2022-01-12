#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
void helper(vector<int> arr, vector<int> &result, int sizeOfResult)
{
    if (result.size() == arr.size() || result.size() == 3)
    {
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > result[sizeOfResult - 1] || result.size() == 0)
        {
            result.push_back(arr[i]);
            helper(arr, result, sizeOfResult + 1);
            result.pop_back();
        }
    }
}
vector<int> find3Numbers(vector<int> arr, int N)
{
    vector<int> result(1, INT_MIN);
    helper(arr, result, 1);
    return result;
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 1, 1, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = find3Numbers(arr, N);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
