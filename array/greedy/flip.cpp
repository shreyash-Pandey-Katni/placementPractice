#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <map>

using namespace std;
vector<int> flip(string A)
{
    int maxSum = 0;
    int currentSum = 0;
    int left = 1, right = 1;
    int tempLeft = 1;
    vector<int> B;
    int n = A.size();
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        int value = A[i] == '1' ? -1 : 1;
        if (currentSum + value < 0)
        {
            currentSum = 0;
            tempLeft = i + 2;
        }
        else
        {
            currentSum += value;
            if (currentSum > maxSum || (currentSum == maxSum && tempLeft < left))
            {
                maxSum = currentSum;
                left = tempLeft;
                right = i + 1;
            }
        }
    }
    if (maxSum <= 0)
        return {};
    return {left, right};
}

int main(int argc, char const *argv[])
{
    string A = "010";
    vector<int> result = flip(A);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
