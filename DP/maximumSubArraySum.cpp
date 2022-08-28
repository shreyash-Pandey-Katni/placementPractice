#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> array)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = 0; i < array.size(); i++)
    {
        curr_sum += array[i];
        max_sum = max(max_sum, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
    // code here
}