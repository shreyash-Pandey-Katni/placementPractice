#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int getMaximumGenerated(int n)
{
    vector<int> temp(n + 1, 0);
    temp[0] = 0;
    if (n <= 1)
        return n;
    temp[1] = 1;
    int res = 0;
    for (int i = 2; i < n + 1; i++)
    {
        if (i%2 == 1)
        temp[i] = temp[i / 2] + temp[i / 2 +1];
        else
            temp[i] = temp[i/2];
        res = max(res, temp[i]);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << getMaximumGenerated(n);
    return 0;
}
