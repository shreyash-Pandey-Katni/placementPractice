#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int equilibriumPoint(long long a[], int n)
{
    if (n==1)
    {
        return 1;
    }
    if (n==2){
        return -1;
    }
    long long rightSum=0;
    long long leftSum=0;
    for (int i=1;i<n;i++)
    {
        rightSum+=a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        leftSum+=a[i];
        rightSum-=a[i+1];
        if (leftSum==rightSum)
        {
            return i+1;
        }
    }
    return -1;
}