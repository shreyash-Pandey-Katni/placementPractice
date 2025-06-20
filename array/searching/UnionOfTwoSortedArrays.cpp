#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0;
    int j = 0;
    vector<int> result;
    set<int> setA;
    while (i < n || i < m)
    {
        if(i<n)
        {
            setA.insert(arr1[i]);
        }
        if(i<m)
        {
            setA.insert(arr2[i]);
        }
        i++;
    }
    for(auto itr=setA.begin();itr!=setA.end();itr++)
    {
        result.push_back(*itr);
    }
    return result;
}