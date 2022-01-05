#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> duplicates(int arr[], int n)
{
    unordered_map<int, int> map;
    unordered_map<int, int> resultMap;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (map.find(arr[i]) != map.end() && resultMap.find(arr[i]) == resultMap.end())
        {
            resultMap[arr[i]] = 1;
            result.push_back(arr[i]);
        }
        else
        { 
            map[arr[i]] = 1;
        }
    }
    sort(result.begin(), result.end());
    return result.size() != 0 ? result : vector<int>{-1};
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> result = duplicates(arr, n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
