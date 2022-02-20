#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp;
int findPivot(vector<int> a, int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}
void findKLargest(vector<int> &v, int k, int low, int high, vector<int>&res)
{
    if (low < high)
    {
        int pIndex = findPivot(v, low, high);
        if (pIndex == k)
        {
            res.insert(res.begin(), v.end() - k, v.end());
            return;
        }
        else if (pIndex < k)
        {
            findKLargest(v, k, pIndex + 1, high, res);
        }
        else
        {
            findKLargest(v, k, low, pIndex - 1, res);
        }
    }
}

int solve(vector<int> &v, int availableEnergy, int leftJumpsOfTeleports){
    int n = v.size();
    vector<int> res;
    vector<int> cost;
    for(int i=0;i<n-1;i++){
        cost.push_back(abs(v[i]-v[i+1]));
    }
    findKLargest(cost, leftJumpsOfTeleports, 0, n-1, res);
    unordered_map<int, int>mp;
    for(int i=0;i<res.size();i++){
        mp[res[i]]++;
    }
    for (int i = 0; i < n-1; i++)
    {
        if(leftJumpsOfTeleports == 0 && availableEnergy == 0){
            return i+1;
        }
        if(mp.find(cost[i]) != mp.end() || availableEnergy < cost[i] && leftJumpsOfTeleports > 0){
            leftJumpsOfTeleports--;
            continue;
        }
        availableEnergy -= cost[i];
    }
    return n;
}
int main(int argc, char const *argv[])
{
    int n, k, X;
    cin >> n >> k >> X;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(v, X, k) << endl;
    return 0;
}
