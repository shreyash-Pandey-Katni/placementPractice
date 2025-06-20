#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int> &A)
{
    int oldIndex = 0;
    int newIndex = 0;
    int n = A.size();
    int countZero = 0;
    for (int i = 0; i < n; i++, oldIndex++)
    {
        if (A[oldIndex] == 0)
        {
            countZero++;
        }
        else
        {
            A[newIndex++] = A[oldIndex];
        }
    }
    for (int i = n - 1; i >= n - countZero; i--)
    {
        A[i] = 0;
    }
    return A;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {0};
    vector<int> result = solve(A);
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
