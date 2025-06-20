#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(const vector<int> &A)
{
    int maxSum = A[0];
    int currentSum = A[0];

    for (int i = 1; i < A.size(); i++)
    {
        currentSum = max(A[i], currentSum + A[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main(int argc, char const *argv[])
{
    // Example usage
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(A);
    cout << "Maximum Sum Contiguous Subarray: " << result << endl;
    // Output: 6 (subarray: [4, -1, 2, 1])
    // Another example
    vector<int> B = {-1, -2, -3, -4};
    int result2 = maxSubArray(B);
    cout << "Maximum Sum Contiguous Subarray: " << result2 << endl;
    return 0;
}
