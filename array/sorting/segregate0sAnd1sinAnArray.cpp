#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solve(vector<int> &A)
{
    int n = A.size();
    int leftIndex = 0;
    int rightIndex = n - 1;
    while (leftIndex < rightIndex)
    {
        if (A[leftIndex] == 0 && A[rightIndex] == 1)
        {
            leftIndex++;
            rightIndex--;
        }
        else if (A[leftIndex] == 1 && A[rightIndex] == 0)
        {
            swap(A[leftIndex], A[rightIndex]);
        }
        else if (A[rightIndex] == 0)
        {
            leftIndex++;
        }
        else if (A[leftIndex] == 1)
        {
            rightIndex--;
        }
    }
    return A;
}
int main(int argc, char const *argv[])
{
    vector<int> A = {0, 1, 0, 1, 0, 1};
    vector<int> result = solve(A);
    cout << "Segregated array: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
