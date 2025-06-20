#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &A)
{
    int n = A.size();
    vector<int> rightOddIndexSum(n, 0), rightEvenIndexSum(n, 0);
    int tempRightOddIndexSum = 0, tempRightEvenIndexSum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {

            rightEvenIndexSum[i] = tempRightEvenIndexSum;
            tempRightEvenIndexSum += A[i];
            rightOddIndexSum[i] = tempRightOddIndexSum;
        }
        else
        {
            rightOddIndexSum[i] = tempRightOddIndexSum;
            tempRightOddIndexSum += A[i];
            rightEvenIndexSum[i] = tempRightEvenIndexSum;
        }
    }
    int tempLeftOddIndexSum = 0, tempLeftEvenIndexSum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (tempLeftOddIndexSum + rightEvenIndexSum[i] == tempLeftEvenIndexSum + rightOddIndexSum[i])
            count++;
        if (i % 2 == 0)
        {
            tempLeftEvenIndexSum += A[i];
        }
        else
        {
            tempLeftOddIndexSum += A[i];
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    // nput 1:

    // A = [ 2, 1, 6, 4 ] Input 2 :

    //     A = [ 5, 5, 2, 5, 8 ]
    vector<int> A = {2, 1, 6, 4};
    cout << solve(A) << endl; // Output: 1
    A = {5, 5, 2, 5, 8};
    cout << solve(A) << endl; // Output: 2
    return 0;
}
