#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n){
    int newNumberOfWeights = 0;
    int newWt[n];
    int newVal[n];
    for (int i = 0; i < n; i++)
    {
        if (wt[i] <= W)
        {
            newNumberOfWeights++;
            // W -= wt[i];
        }
    }

}