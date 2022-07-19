#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A, vector<int> &B)
{
    int count = 0;
    int n = A.size();
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < n; i++)
    {
        sumA += A[i];
        sumB += B[i];
    }
    int tempSumA = 0;
    int tempSumB = 0;
    for (int i = 0; i < n; i++)
    {
        tempSumA += A[i];
        tempSumB += B[i];
        if (tempSumA == tempSumB && tempSumA == sumA - tempSumA && tempSumB == sumB - tempSumB)
        {
            count++;
        }
    }
    return count;
}