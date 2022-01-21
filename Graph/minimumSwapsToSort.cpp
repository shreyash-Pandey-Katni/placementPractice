#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
int countNum = 0;

int minSwaps(vector<int> &nums)
{
    int swapNum = 0;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != temp[i])
        {
            int init = temp[i];
            swap(nums[hash[temp[i]]], nums[i]);
            swapNum++;
            hash[init] = hash[temp[i]];
            hash[temp[i]] = i;
        }
    }
    return swapNum;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {2, 8, 5, 4};
    cout << minSwaps(nums) << endl;
    return 0;
}
