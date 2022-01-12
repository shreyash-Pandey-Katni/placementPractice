#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int max_sum(int A[], int N){
    int cumSum = 0;
    int currSum = 0;
    int res = INT_MIN;
    for (int i = 0; i < N;i++){
        cumSum += A[i];
        currSum += i*A[i];
    }
    res = max(res, currSum);
    for (int i = 0; i < N; i++){
        currSum = currSum -(cumSum-A[i]) + A[i]*(N-1);
        res = max(res, currSum);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int A[] = {8,3,1,2};
    int N = sizeof(A)/sizeof(A[0]);
    cout<<max_sum(A, N)<<endl;
    return 0;
}
