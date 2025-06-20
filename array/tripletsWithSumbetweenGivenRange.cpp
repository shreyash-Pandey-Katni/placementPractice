#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(vector<string> &A)
{

    int n = A.size();
    if (n < 3)
        return 0;

    sort(A.begin(), A.end());
    int i = 0, j = n - 1;
    int mid;
    double sum = 0;
    while (i < j)
    {
        mid = (i + j) / 2;
        sum = stod(A[i]) + stod(A[j]) + stod(A[mid]);
        if (sum < 2.0 && sum > 1.0)
        {
            // We found a triplet with sum in the range [1, 2]
            return 1; // Found a triplet with sum in the range [1, 2]
        }
        else if (sum >= 2.0)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    // A : [ "2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191" ]
    vector<string> A = {"2.673662", "2.419159", "0.573816", "2.454376", "0.403605", "2.503658", "0.806191"};
    int result = solve(A);
    if (result == 1)
        cout << "Yes, it is possible to make all elements equal." << endl;
    else
        cout << "No, it is not possible to make all elements equal." << endl;
    // A : [ "0.503094", "0.648924", "0.999298" ]
    vector<string> B = {"0.503094", "0.648924", "0.999298"};
    int result2 = solve(B);
    if (result2 == 1)
        cout << "Yes, it is possible to make all elements equal." << endl;
    else
        cout << "No, it is not possible to make all elements equal." << endl;
    return 0;
}
