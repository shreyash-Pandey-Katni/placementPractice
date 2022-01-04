#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int minDist(int a[], int n, int x, int y){
    int indexX = -1;
    int indexY = -1;
    for (int i = 0; i < n && (indexX==-1 || indexY == -1); i++)
    {
        if(a[i] == x){
            indexX = i;
        }
        if(a[i] == y){
            indexY = i;
        }
    }
    return abs(indexX-indexY);
}