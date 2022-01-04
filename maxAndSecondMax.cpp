#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = INT_MIN;
    int secondMax = INT_MIN;
    for (int i = 0; i < sizeOfArray; i++)
    {
        if(arr[i]> max){
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i]>secondMax){
            secondMax = arr[i];
        }
    }
    return vector<int>{max,secondMax};
}