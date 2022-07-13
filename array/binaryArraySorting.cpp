#include<iostream>
#include<vector>
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray)
{
    int sum = 0;
    for (int i = 0; i < binArray.size(); i++)
    {
        sum += binArray[i];
    }
    vector<int> result;
    int i = 0;
    while(i<binArray.size()-sum)
    {
        result.push_back(0);
        i++;
    }
    while(i<binArray.size())
    {
        result.push_back(1);
        i++;
    }
    return result;
}