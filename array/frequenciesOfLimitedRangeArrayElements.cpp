#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void frequencyCount(vector<int> &arr, int N, int P)
{
    unordered_map<int, int> map;
    for (int i = 0;i<N;i++)
    {
        map[arr[i]]++;
    }
    
}