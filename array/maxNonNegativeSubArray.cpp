#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> maxset(vector<int> &A){
    vector<int> subArray = {};
    long long int tempSum = 0;
    long long int maxSum = 0;
    unordered_map<long long int, vector<int>> sumMap;
    for(int i = 0;i<A.size(); i++){
        if(A[i] < 0) {
            if (tempSum >= maxSum) {
                maxSum = tempSum;
                if (sumMap.find(maxSum) == sumMap.end())
                    sumMap.insert({maxSum, subArray});
                else {
                    if (subArray.size() > sumMap[maxSum].size())
                    sumMap[maxSum] = subArray;
                }
            }
            tempSum = 0;
            subArray = {};
        }
        else {
            tempSum += A[i];
            subArray.push_back(A[i]);
        }
    }
    if (tempSum >=maxSum){
        maxSum = tempSum;
                if (sumMap.find(maxSum) == sumMap.end())
                    sumMap.insert({maxSum, subArray});
                else {
                    if (subArray.size() > sumMap[maxSum].size())
                    sumMap[maxSum] = subArray;
                }
    }
    return sumMap[maxSum];
}


int main(){
    vector<int> A = {1967513926, 1540383426, -1303455736, -521595368};
    vector<int> B = maxset(A);
    for (int i = 0; i < B.size(); i++)
    {
        cout<<B[i]<<" ";
    }
    
}