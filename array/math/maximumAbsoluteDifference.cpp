#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int maxArr(vector<int> &A)
{
    vector<int> addedIndex;
    vector<int> subtractedIndex;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        addedIndex.push_back(A[i] + i);
        subtractedIndex.push_back(A[i] - i);
    }
        int maxOfAddedArray = INT_MIN, maxOfSubtractedArray = INT_MIN;
    int minOfAddedArray = INT_MAX, minOfSubtractedArray = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (maxOfAddedArray < addedIndex[i])
        {
            maxOfAddedArray = addedIndex[i];
        }
        if (minOfAddedArray > addedIndex[i])
        {
            minOfAddedArray = addedIndex[i];
        }
        if (maxOfSubtractedArray < subtractedIndex[i])
        {
            maxOfSubtractedArray = subtractedIndex[i];
        }
        if (minOfSubtractedArray > subtractedIndex[i])
        {
            minOfSubtractedArray = subtractedIndex[i];
        }
    }
    return max(maxOfAddedArray - minOfAddedArray, maxOfSubtractedArray-minOfSubtractedArray);
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 3, -1};
    cout << maxArr(A) << endl;
    return 0;
}
