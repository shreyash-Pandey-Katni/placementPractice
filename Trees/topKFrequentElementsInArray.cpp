#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// #define int long long int
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
vector<int> topK(vector<int> &nums, int k)
{
    vector<pair<int, int>> v;
    sort(nums.begin(), nums.end());
    int last = nums[0];
    v.push_back(make_pair(nums[0], 1));
    for (int i = 1; i < nums.size(); i++)
    {
        if (last == nums[i])
        {
            v[v.size() - 1].second++;
        }
        else
        {
            last = nums[i];
            v.push_back(make_pair(nums[i], 1));
        }
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        res.push_back(v[v.size()-1-i].first);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topK(nums, k);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
