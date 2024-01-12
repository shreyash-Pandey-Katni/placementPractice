#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]){
    int max = -1;
    int secondMax = -1;
    for(int i = 0;i<sizeOfArray;i++){
        if (arr[i]>max){
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i]>secondMax && arr[i] != max){
            secondMax = arr[i];
        }
    }
    return vector<int>({max, secondMax});
}

int main() {
    int arr[] = {2 ,1, 2};
    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
    vector<int> result = largestAndSecondLargest(sizeOfArray, arr);
    cout << "The largest number is " << result[0] << endl;
    cout << "The second largest number is " << result[1] << endl;
    return 0;
}