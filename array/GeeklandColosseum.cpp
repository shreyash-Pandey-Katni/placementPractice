#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

//There are 3*N numbers in the array. Remove N numbers from the array. Divide the array into 2 parts.
// Find the maximum difference between the sum of two parts.
// Input:
// The first line contains an integer N, denoting the number of elements in the array.
// The second line contains N space separated integers, denoting the elements of the array.


long long elementRemoval(vector<int> arr, int n)
{
    int numbersToRemove;
    if(n%2 == 0){
        numbersToRemove = n/2;
    }
    else{
        numbersToRemove = (n-1)/2;
        arr.erase(arr.begin()+arr.size()/2);
    }
    sort(arr.begin(), arr.begin() +arr.size()/2);
    sort(arr.begin()+arr.size()/2, arr.end());
    long long sum = 0;
    for (int i = numbersToRemove; i < (arr.size())/2;i++){
        sum += arr[i] - arr[arr.size() - i - 1];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<elementRemoval(arr,n/3);
    return 0;
}
