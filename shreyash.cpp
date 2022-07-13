#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v = {-1, 5, 10, 20, 28, 3};
    vector<int> v2 = {26, 134, 135, 15, 17};

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    int i = 0;
    int j = 0;
    int k = 0;

    int diff = INT_MAX;
    int diffI = i;
    int diffJ = j;

    while (i < v.size() && j < v2.size() && k < v.size() * v2.size())
    {
        int temp = abs(v[i] - v2[j]);
        if (temp < diff)
        {
            diff = temp;
            diffI = i;
            diffJ = j;
        }
        if (i < v.size() - 1 && abs(v[i + 1] - v2[j]) <= temp)
        {
            i++;
            continue;
        }
        else if (j < v2.size() - 1 && abs(v[i] - v2[j + 1]) <= temp)
        {
            j++;
            continue;
        }
        k++;
    }
    cout << v[diffI] << " " << v2[diffJ];
    return 0;
}
