#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isMountain(int arr[], int n)
{
    int i = 0;
    while (i < n - 1 && arr[i] < arr[i + 1])
        i++;
    if (i == n - 1)
        return false;
    while (i < n - 1 && arr[i] > arr[i + 1])
        i++;
    return i == n - 1;
}

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,int q)
{
    vector<bool> ans;
    for (int i = 0; i < q; i++)
    {
        int temp[queries[i].second - queries[i].first + 1];
        
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
