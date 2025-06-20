#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> addArrays(vector<int> &A, vector<int> &B)
{
    vector<int> result;
    vector<int> temp;
    int lengthA = A.size();
    int lengthB = B.size();
    int sum = 0;
    int carry = 0;

    while (lengthA > 0 && lengthB > 0)
    {
        sum = A[lengthA - 1] + B[lengthB - 1] + carry;
        if (sum / 10 > 0)
        {
            carry = sum / 10;
            sum = sum % 10;
        } else
        {
            carry = 0;
        }
        lengthA--;
        lengthB--;
        temp.push_back(sum);
    }
    while (lengthA > 0)
    {
        sum = A[lengthA - 1] + carry;
        if (sum / 10 > 0)
        {
            carry = sum / 10;
            sum = sum % 10;
        } else
        {
            carry = 0;
        }
        temp.push_back(sum);
        lengthA--;
    }
    while (lengthB > 0)
    {
        sum = B[lengthB - 1] + carry;
        if (sum / 10 > 0)
        {
            carry = sum / 10;
            sum = sum % 10;
        } else
        {
            carry = 0;
        }
        temp.push_back(sum);
        lengthB--;
    }
    if (carry > 0)
    {
        result.push_back(carry);
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        result.push_back(temp[i]);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    // A : [ 4, 3, 6, 7, 9, 9, 1, 7, 8 ]
    // B : [ 7, 5, 8, 9 ]
    vector<int> A = {4, 3, 6, 7, 9, 9, 1, 7, 8};
    vector<int> B = {7, 5, 8, 9};
    vector<int> result = addArrays(A, B);
    cout << "Result: ";
    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
