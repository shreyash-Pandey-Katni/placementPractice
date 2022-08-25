#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    priority_queue<int> pq;
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pq.push(matrix[i][j]);
            if (pq.size() > k)
                pq.pop();
        }
    }
    return pq.top();
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    cout << kthSmallest(matrix, k) << endl;
    return 0;
}
