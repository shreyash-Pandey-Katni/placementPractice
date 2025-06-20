#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> intersection(vector<int>& num1, vector<int>& num2){
    unordered_set<int> s1(num1.begin(), num1.end());
    unordered_set<int> s2(num2.begin(), num2.end());
    vector<int> res;
    for(auto i : s1){
        if(s2.find(i) != s2.end()){
            res.push_back(i);
        }
    }
    return res;
}