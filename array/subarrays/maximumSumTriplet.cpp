#include <iostream>
#include <vector>
#include <limits.h>
#include <set>
using namespace std;

int maxInSetUsingBinarySearch(set<int> &s, int val)
{
    auto it = s.lower_bound(val);
    if (it == s.begin())
        return INT_MIN;
    --it;
    return *it;
}

int solve(vector<int> &A)
{
    int maxSum = INT_MIN;
    int sum;
    int n = A.size();
    set<int> s;
    s.insert(A[0]);
    vector<int> maxRight(n, INT_MIN);
    maxRight[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxRight[i] = max(maxRight[i + 1], A[i+1]);
    }
    for (int j = 1; j < n - 1; j++)
    {
        int maxI = INT_MIN;
        int maxK = INT_MIN;
        int val = A[j];
        maxI = maxInSetUsingBinarySearch(s, val);
        s.insert(A[j]);

        maxK = maxRight[j] > A[j] ? maxRight[j] : INT_MIN;
        if (maxI != INT_MIN && maxK != INT_MIN)
        {
            sum = maxI + A[j] + maxK;
            maxSum = max(maxSum, sum);
        }
    }

    if (maxSum == INT_MIN)
        return 0;
    return maxSum;
}
int main(int argc, char const *argv[])
{
    // A : [ 3603, 24351, 10292, 30837, 9375, 11021, 4597, 24022, 27349, 23200, 19669, 24485, 8282, 4735, 54, 2000, 26419, 27939, 6901, 3789, 18128, 468, 3729, 14894, 24649, 22484, 17808, 2422, 14311, 6618, 22814 ]
    vector<int> A = {3603, 24351, 10292, 30837, 9375, 11021, 4597, 24022, 27349, 23200, 19669, 24485, 8282, 4735, 54, 2000, 26419, 27939, 6901, 3789, 18128, 468, 3729, 14894, 24649, 22484, 17808, 2422, 14311, 6618, 22814};

    int result = solve(A);
    cout << "Maximum Sum Triplet: " << result << endl;
    return 0;
}
