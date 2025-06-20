#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> generateMatrix(int A)
{
    vector<vector<int>> result(A, vector<int>(A, 0));
    int leftBoundry = 0;
    int rightBoundry = A - 1;
    int topBoundry = 0;
    int bottomBoundry = A - 1;
    int i = 0, j = 0;
    int count = 1;
    int countLimit = A * A;
    while (leftBoundry <= rightBoundry && topBoundry <= bottomBoundry && count <= countLimit)
    {
        for (i = leftBoundry; i <= rightBoundry; i++, count++)
        {
            result[j][i] = count;
        }
        topBoundry++;
        i--;
        for (j = topBoundry; j <= bottomBoundry; j++, count++)
        {
            result[j][i] = count;
        }
        rightBoundry--;
        j--;
        for (i = rightBoundry; i >= leftBoundry; i--, count++)
        {
            result[j][i] = count;
        }
        bottomBoundry--;
        i++;
        for (j = bottomBoundry; j >= topBoundry; j--, count++)
        {
            result[j][i] = count;
        }
        j++;
        leftBoundry++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int A;
    cout << "Enter the size of the matrix: ";
    cin >> A;
    vector<vector<int>> matrix = generateMatrix(A);
    cout << "Generated Spiral Order Matrix:" << endl;
    for (const auto &row : matrix)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
