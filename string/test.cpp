#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int recursion(vector<int> arr, int n, int b, vector<int> curr){
    if(n>b){
        return max(recursion(arr, n-1, b, curr), recursion(arr, n-1, b+1, curr));
    }
    int ans = 0;
    if(b==1){
        for (int i = 0; i < n; i++)
        {
            ans = ans | arr[i];
            return ans;
        }
    }
    if(n == b){
        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
        }
        return ans;
    }
}
int main(int argc, char const *argv[])
{
    int n, b;
    cin >> n >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << recursion(arr, n, b, arr);
    return 0;
}
