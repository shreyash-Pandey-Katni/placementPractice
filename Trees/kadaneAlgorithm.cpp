#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long
ll maxSumContiguousSubArray(int arr[], int n)
{
    long long maxSum = INT_MIN;
    long long currSum = 0;
    bool allNegative = true;
    int maxElement = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (allNegative && arr[i] >= 0)
        {
            allNegative = false;
        }
        maxElement = max(maxElement, arr[i]);
        currSum = currSum + arr[i];
        if (currSum > maxSum)
        {
            maxSum = currSum;
        }
        if (currSum < 0)
        {
            currSum = 0;
        }
    }
    return allNegative ? maxElement : maxSum;
}