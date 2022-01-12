#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define ll long long int
bool find3Numbers(int A[], int n, int target)
{
    if (n < 3)
        return false;
    if (n == 3)
        return A[0] + A[1] + A[2] == target;
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = A[i] + A[l] + A[r];
            if (sum < target)
            {
                l++;
            }
            else if (sum > target)
            {
                r--;
            }
            else
                return true;
        }
    }
    return false;
}