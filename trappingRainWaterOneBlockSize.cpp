#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
ll trappingWater(int arr[], int n){
    int maxHeight = 0;
    int maxIndex = 0;
    ll sum = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n;i++){
        maxHeight = max(maxHeight, arr[i]);
        if (maxHeight == arr[i]){
            maxIndex = i;
        }
        dp[i] = maxHeight;
    }
}