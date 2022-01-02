#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
int trap(vector<int> &heights){
    int maxHeight = 0;
    int maxIndex = 0;
    int sum = 0;
    vector<int> dp(heights.size(), 0);
    for (int i = 0; i < heights.size();i++){
        maxHeight = max(maxHeight, heights[i]);
        if (maxHeight == heights[i]){
            maxIndex = i;
        }
        dp[i] = maxHeight;
    }
    int tempMaxHeight = 0;
    vector<int> tempDp(heights.size(), 0);
    for (int i = heights.size() - 1; i >= maxIndex; i--)
    {
        tempMaxHeight = max(tempMaxHeight, heights[i]);
        tempDp[i] = tempMaxHeight;
    }
    int sum = 0;
    for (int i = 0; i < maxIndex; i++)
    {
        sum += dp[i] - heights[i];
    }
    for (int i = maxIndex; i < heights.size(); i++)
    {
        sum += tempDp[i] - heights[i];
    }
    return sum;
}