#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int first(vector<int> nums, int low, int high, int target){
    int ans = -1;
    while(low < high){
        int mid = (low + high) / 2;
        if(nums[mid]<target){
            low = mid + 1;
        }
        else if(nums[mid]>target){
            high = mid - 1;
        }
        else if(nums[mid] == target){
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int last(vector<int>nums, int low, int high, int target){
    int ans = -1;
    while(low< high){
        int mid = (low + high) / 2;
        if(nums[mid]< target){
            low = mid + 1;
        }
        else if(nums[mid]> target){
            high = mid - 1;
        }
        else if(nums[mid] == target){
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {first(nums, 0, nums.size()-1, target), last(nums, 0, nums.size()-1, target)};
}