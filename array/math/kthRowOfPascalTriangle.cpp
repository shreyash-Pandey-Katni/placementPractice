#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getRow(int A)
{
    vector<int> result(A, 0);
    result[0] = 1;
    for (int i = 1; i < A; i++)
    {
        for (int j = i; j > 0; j--)
        {
            result[j] = result[j] + result[j - 1];
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int A = 2;
    vector<int> result = getRow(A);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
