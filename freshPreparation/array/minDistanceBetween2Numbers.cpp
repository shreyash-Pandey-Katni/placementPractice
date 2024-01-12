#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int minDist(int a[], int n, int x, int y)
{
    vector<int> xIndexs;
    vector<int> yIndexs ;
    for(int i=0;i<n;i++){
        if (a[i] == x){
            xIndexs.push_back(i);
        }
        else if (a[i] == y)
        {
            yIndexs.push_back(i);
        }        
    }
    if (xIndexs.size() == 0 || yIndexs.size() == 0){
        return -1;
    }
    int minDist = INT_MAX;
    for(int i = 0; i<xIndexs.size();i++){
        for(int j=0;j<yIndexs.size();j++){
            if (abs(xIndexs[i] - yIndexs[j]) < minDist){
                minDist = abs(xIndexs[i] - yIndexs[j]);
            }
        }
    }
    return minDist;
}

int main() {
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int y = 6;

    cout << "Minimum distance between " << x << " and " << y << " is " << minDist(arr, n, x, y) << endl;
    return 0;
}