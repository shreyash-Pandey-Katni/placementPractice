#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int min(int a, int b)
{
    return a < b ? a : b;
}
int minDist(int a[], int n, int x, int y)
{
    int prev = -1;
    int minDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x || a[i] == y)
        {
            if (prev != -1 && a[i] != a[prev])
            {
                minDist = min(minDist, i - prev);
            }
            prev = i;
        }
    }
    return minDist == INT_MAX ? -1 : minDist;
}
int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 1, y = 2;
    cout << minDist(a, n, x, y) << endl;
    return 0;
}
