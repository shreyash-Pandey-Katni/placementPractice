#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> kthLargestElements(int arr[], int n, int k){
    vector<int> result(INT_MIN, k);
    for(int i = 0; i < n; i++){
        if(result.size() == k){
            if(arr[i] > result[0]){
                result.erase(result.begin());
                result.push_back(arr[i]);
            }
        }
        else{
            result.push_back(arr[i]);
        }
    }
    return result;
}