#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> removeDuplicate(vector<int> &arr, int n){
    unordered_map<int, int> map;
    vector<int> result;
    for(int i = 0; i < n; i++){
        if(map.find(arr[i]) == map.end()){
            map[arr[i]] = 1;
            result.push_back(arr[i]);
        }
    }
    return result;
}