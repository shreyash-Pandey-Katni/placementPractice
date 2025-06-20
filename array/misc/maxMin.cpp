#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int solve(vector<int> &A)
{
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int n = A.size();
    if (n == 0)
    {
        return 0;
    } else if (n == 1)
    {
        return 2 * A[0];
    }

    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, A[i]);
        minVal = min(minVal, A[i]);
    }
    return maxVal + minVal;
}
