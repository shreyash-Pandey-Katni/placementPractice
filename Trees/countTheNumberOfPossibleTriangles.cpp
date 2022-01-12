#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findNumberOfTriangles(int arr[], int n){
    sort(arr, arr+n);
    int count = 0;
    int tempCount = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int l = 0;
        int r = i-1;
        while (l<r)
        {
            if (arr[l] + arr[r] > arr[i])
            {
                count += r - l;
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findNumberOfTriangles(arr, n);
    return 0;
}
