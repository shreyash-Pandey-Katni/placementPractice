#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int maxPathSum(int A[], int B[], int l1, int l2)
{
    int maxSum = INT_MIN;
    // int sum = 0;
    int sumA = 0, sumB = 0;
    int forwardSumA = 0;
    int forwardSumB = 0;
    int index = 0;
    bool indexUpdated = false;
    int indexI1 = l1 - 1;
    int indexI2 = l2 - 1;
    while (indexI1 >= 0 && indexI2 >= 0)
    {
        if (indexUpdated)
        {
            if (A[indexI1] > B[indexI2])
            {
                forwardSumA += A[indexI1--];
            }
            else
            {
                forwardSumB += B[indexI2--];
            }
            continue;
        }
        if (A[indexI1] == B[indexI2])
        {
            maxSum = max(sumA, sumB) + A[indexI1];
            indexI1--;
            indexI2--;
            indexUpdated = true;
            continue;
        }
        if (A[indexI1] > B[indexI2])
        {
            sumA += A[indexI1--];
        }
        else
        {
            sumB += B[indexI2--];
        }
    }
    while (indexI1 >= 0)
    {
        forwardSumA += A[indexI1--];
    }
    while (indexI2 >= 0)
    {
        forwardSumB += B[indexI2--];
    }
    return maxSum + (forwardSumA > forwardSumB ? forwardSumA : forwardSumB);
}
int main(int argc, char const *argv[])
{
    int A[] = {2, 3, 7, 10, 12};
    int B[] = {1, 5, 7, 8};
    int l1 = sizeof(A) / sizeof(A[0]);
    int l2 = sizeof(B) / sizeof(B[0]);
    cout << maxPathSum(A, B, l1, l2);
    return 0;
}
