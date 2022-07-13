#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

long long reverseCount(int N, int* A){
    vector<int> B;
    vector<vector<int>> adj;
    for(int i=0;i<N-1;i++){
        if(A[i]>A[i+1]){
            B.push_back(A[i]);
        }
        else{
            adj.push_back(B);
            B.clear();
            B.push_back(A[i+1]);
        }
    }
    adj.push_back(B);
    
}