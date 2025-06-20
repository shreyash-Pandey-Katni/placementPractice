#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int minContiguousArray(int arr[], int n){
    int minSoFar = INT_MAX;
    int minEndingHere = 0;
    for(int i = 0; i < n; i++){
        minEndingHere += arr[i];
        if(minEndingHere < minSoFar){
            minSoFar = minEndingHere;
        }
        if(minEndingHere > 0){
            minEndingHere = 0;
        }
    }
    return minSoFar;
}
int maxContiguousArray(int arr[], int n){
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    for(int i = 0; i < n; i++){
        maxEndingHere += arr[i];
        if(maxEndingHere > maxSoFar){
            maxSoFar = maxEndingHere;
        }
        if(maxEndingHere < 0){
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
}
int circularSubarraySum(int arr[], int n){
    int sum = 0;
    for (int i = 0;i<n;i++){
        sum += arr[i];
    }
    int minSoFar = arr[0];
    int maxSoFar = arr[0];
    int minEndingHere = arr[0];
    int maxEndingHere = arr[0];
    for (int i = 1;i<n;i++){
        minEndingHere = min(minEndingHere + arr[i], arr[i]);
        maxEndingHere = max(maxEndingHere + arr[i], arr[i]);
        minSoFar = min(minSoFar, minEndingHere);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    if(minSoFar == sum){
        return maxSoFar;
    }
    return max(maxSoFar, sum - minSoFar);
}