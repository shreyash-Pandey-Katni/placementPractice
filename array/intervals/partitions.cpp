#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve(int A, vector<int> &B)
{
    long sum = 0;
    for (int i = 0; i < A; i++)
    {
        sum += B[i];
    }
    if (sum % 3 != 0)
    {
        return 0;
    }
    long targetSum = sum / 3;
    int result = 0;
    sum = 0;
    int count = 0;
    for (int i = 0; i < A-1; i++)
    {
        sum += B[i];
        if (sum == 2 * targetSum)
        {
            result += count;
        }
        if (sum == targetSum)
        {
            count++;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int A = 5;
    vector<int> B = {1, 2, 3, 0, 3};
    cout << solve(A, B) << endl;
    A = 4;
    B = {1, 2, 3, 0};
    cout << solve(A, B) << endl;
    A = 3;
    B = {1, 2, 3};
    cout << solve(A, B) << endl;
    A = 6;
    B = {1, 2, 3, 0, 3, 0};
    cout << solve(A, B) << endl;
    // A : 4
    // B: [ 0, 1, -1, 0 ]
    A = 4;
    B = {0, 1, -1, 0};
    cout << solve(A, B) << endl;
    return 0;
}
