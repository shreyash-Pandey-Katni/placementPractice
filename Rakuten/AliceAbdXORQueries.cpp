#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

long long XOR(long long a, long long b) {
    return a ^ b;
}

vector<long long> solve(int Q, vector<int> type, vector<int> X){
    unordered_map<int, long long> countOfX;
    vector<long long> ans;
    for (int i = 0; i < Q;i++){
        if(type[i] == 1){
            if(countOfX.find(X[i]) == countOfX.end()){
                countOfX[X[i]] = 1;
            }
            else{
                countOfX[X[i]]++;
            }
        }
        else if(type[i] == 2){
            if(countOfX.find(X[i]) != countOfX.end()){
                countOfX.erase(X[i]);
            }
        }
        else{
            if(countOfX.size() == 0){
                ans.push_back(0);
            }
            else{
                long long sum = 0;
                for(auto it = countOfX.begin(); it != countOfX.end(); it++){
                    if(it->second != 0){
                        sum += XOR(it->first, X[i]) * it->second;
                    }
                }
                ans.push_back(sum);
            }
        }
    }
    return ans;
}
