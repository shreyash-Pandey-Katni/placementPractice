#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> diagonal(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> result;
    int startI = 0, startJ = 0, endI = 0, endJ = 0;
    int i = 0;
    for (int count = 0; count < 2 * n - 1; count++)
    {
        vector<int> temp;
        i = startI;
        for (int j = startJ; j <= endJ; j++)
        {
            temp.push_back(A[j][i]);
            i--;
        }
        if (endJ == n - 1)
        {
            startJ++;
            endI++;
        }
        else
        {
            startI++;
            endJ++;
        }
        result.push_back(temp);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    vector<vector<int>> result = diagonal(A);
    cout << "Anti-diagonal elements:" << endl;
    for (const auto &row : result)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
