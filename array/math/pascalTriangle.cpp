#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> solve(int A)
{
    if (A <= 0)
    {
        return {};
    }
    vector<vector<int>> result = {vector<int>(1, 1)};
    for (int i = 1; i < A; i++)
    {
        vector<int> temp = {1};
        for (int j = i - 1; j >= 1; j--)
        {
            temp.push_back(result[i - 1][j] + result[i - 1][j - 1]);
        }
        temp.push_back(1);
        result.push_back(temp);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int A;
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> A;
    vector<vector<int>> pascalTriangle = solve(A);
    cout << "Generated Pascal's Triangle:" << endl;
    for (const auto &row : pascalTriangle)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
