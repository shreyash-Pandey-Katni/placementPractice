#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();
    bool ans = false;
    if(matrix[0][0] > target || matrix[m-1][n-1] < target)
        return false;
    for(int i = 0; i < m && !ans; i++){
        if(matrix[i][n-1] >= target && matrix[i][0] <= target){
            if(binarySearch(matrix[i], target)){
                ans = true;
                break;
            }
        }
    }
    return ans;
    return false;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1,  4, 7, 11, 15},
                                  {2,  5, 8, 12, 19},
                                  {3,  6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    cout << searchMatrix(matrix, 5) << endl;
    return 0;
}
