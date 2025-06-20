#include <iostream>
#include <vector>

using namespace std;
vector<int> plusOne(vector<int> &A)
{
    vector<int> result;
    int n = A.size();
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (carry == 0)
        {
            break;
        }
        A[i] += carry;
        if (A[i] / 10 > 0)
        {
            carry = A[i] / 10;
            A[i] = A[i] % 10;
        }
        else
        {
            carry = 0;
        }
    }
    if (carry != 0)
    {
        result.push_back(carry);
        for (int i = 0; i < n; i++)
        {
            result.push_back(A[i]);
        }
    }
    else {
        int i = 0;
        while (i < n && A[i] == 0)
        {
            i++;
        }
        for (; i < n; i++)
        {
            result.push_back(A[i]);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {9, 9, 9};
    vector<int> result = plusOne(A);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    vector<int> B = {0};
    vector<int> result2 = plusOne(B);
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i] << " ";
    }
    cout << endl;
    return 0;
}
