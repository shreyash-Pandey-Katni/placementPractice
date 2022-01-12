#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// #define long long long long int

long long int swapCounts = 0;

vector<long long> merge(vector<long long> left, vector<long long> right)
{
    vector<long long> result;
    long long indexLeft = 0;
    long long indexRight = 0;
    while (indexLeft < left.size() && indexRight < right.size())
    {
        if (left[indexLeft] > right[indexRight])
        {
            swapCounts += left.size() - indexLeft;
            result.push_back(right[indexRight++]);
            // indexRight++;
        }
        else
        {
            result.push_back(left[indexLeft++]);
        }
    }
    while (indexLeft < left.size())
    {
        result.push_back(left[indexLeft++]);
    }
    while (indexRight < right.size())
    {
        result.push_back(right[indexRight++]);
    }
    return result;
}

vector<long long> mergeSort(vector<long long> arr)
{
    if (arr.size() == 1)
    {
        return arr;
    }
    int mid = arr.size() / 2;
    vector<long long> left = mergeSort(vector<long long>(arr.begin(), arr.begin() + mid));
    vector<long long> right = mergeSort(vector<long long>(arr.begin() + mid, arr.end()));
    return merge(left, right);
}

long long int inversionCount(long long arr[], long long N)
{
    swapCounts = 0;
    vector<long long> sorted = mergeSort(vector<long long>(arr, arr + N));
    return swapCounts;
}

int main(int argc, char const *argv[])
{
    long long arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << inversionCount(arr, n);
    return 0;
}
