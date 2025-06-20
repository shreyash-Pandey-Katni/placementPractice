#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    int minElement = A[0], maxElement = INT_MIN, lastModulo = A[0]%B;
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        if(lastModulo != A[i]%B){
            return 0;
        }
        minElement = min(minElement, A[i]);
    }
    for (int i = 0; i < n; i++)
    {
        maxElement = max(maxElement, A[i]);
    }
    if(maxElement-minElement > 2*B)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if(A[i] == minElement || A[i] -B == minElement || A[i] == maxElement || A[i]+B == maxElement)
        continue;
        else
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 2, 3, 4, 5};
    int B = 2;
    int result = solve(A, B);
    if (result == 1)
        cout << "Yes, it is possible to make all elements equal." << endl;
    else
        cout << "No, it is not possible to make all elements equal." << endl;
    // Test case 2
    vector<int> A2 = {2,3,1};
    int B2 = 1;
    int result2 = solve(A2, B2);
    if (result2 == 1)
        cout << "Yes, it is possible to make all elements equal." << endl;
    else
        cout << "No, it is not possible to make all elements equal." << endl;
    return 0;
}
