#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int perfectPeak(vector<int> &A)
{
    int n = A.size();
    vector<int> leftMax = {A[0]};
    vector<int> rightMin(n, A[n - 1]);

    for (int i = 1; i < n; i++)
    {
        leftMax.push_back(max(leftMax[i - 1], A[i - 1]));
    }
    for (int i = n - 2; i >= 0; i--)
    {
        rightMin[i] = min(rightMin[i + 1], A[i + 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (A[i] > leftMax[i] && A[i] < rightMin[i])
        {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // A : [ 9895, 30334, 17674, 23812, 20038, 25668, 6869, 1870, 4665, 27645, 7712, 17036, 31323, 8724, 28254, 28704, 26300, 25548, 15142, 12860, 19913, 32663, 32758 ]
    vector<int> A = {9895, 30334, 17674, 23812, 20038, 25668, 6869, 1870, 4665, 27645, 7712, 17036, 31323, 8724, 28254, 28704, 26300, 25548, 15142, 12860, 19913, 32663, 32758};
    int result = perfectPeak(A);
    cout << "Perfect Peak: " << result << endl;
    return 0;
}
