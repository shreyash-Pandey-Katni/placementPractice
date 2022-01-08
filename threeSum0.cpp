#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
bool findTriplets(int arr[], int n){
    sort(arr, arr+n);
    for (int i = 0; i < n-2; i++)
    {
        int l = i+1;
        int r = n-1;
        while (l < r)
        {
            int sum = arr[i] + arr[l] + arr[r];
            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                r--;
            }
            else
                return true;
        }
    }
    return false;
}