#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
vector<int> duplicates(int arr[], int n)
{
    unordered_map<int, int> m;
    vector<int> res;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if(m.find(arr[i]) != m.end()){
            s.insert(arr[i]);
        }
        else{
            m[arr[i]] = 1;
        }
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        res.push_back(*it);
    }
    if (res.size() == 0)
    {
        return vector<int>({-1});
    }
    return res;
}