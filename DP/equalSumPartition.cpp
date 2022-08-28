#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
bool findPartition(int a[], int n)
{
    if (n <= 1)
        return false;
    sort(a, a + n);
    int i = 0, j = n - 1;
    int sum1 = 0, sum2 = 0;
    while (i <= j)
    {
        if (sum1 == sum2 && i == j)
            return true;
        if (sum1 == sum2)
        {
            // i++;
            // j--;
            sum1 += a[i++];
            sum2 += a[j--];
        }
        else if (sum1 < sum2)
        {
            sum1 += a[i];
            i++;
        }
        else
        {
            sum2 += a[j];
            j--;
        }
    }
    return sum1 == sum2 && i == j+1;
    // code here
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (findPartition(a, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
