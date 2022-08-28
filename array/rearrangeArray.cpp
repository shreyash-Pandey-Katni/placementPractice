#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
void arrange(long long arr[], int n)
{
    vector<long long> temp(n, 0);
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[arr[i]];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}