#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

bool isValid(pair<int, int> p, int n)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < n;
}

int solve(vector<vector<int>> &matrix, int mid)
{
    int count = 0, n = matrix.size(), i = n - 1, j = 0;
    while (i >= 0 && j < n)
    {
        if (matrix[i][j] > mid)
            i--;
        else
        {
            count += (i + 1);
            j++;
        }
    }
    return count;
}
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size(), i = matrix[0][0], j = matrix[n - 1][n - 1];
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        int posi = solve(matrix, mid);
        if (posi < k)
            i = mid + 1;
        else
            j = mid;
    }
    return i;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}
