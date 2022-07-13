#include <iostream>
#include <vector>
using namespace std;

bool isIncreasing(int arr[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}


// function to determine if the array is in decreasing order
bool isDecreasing(int arr[], int start, int end)
{
    for (int i = start; i < end; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return false;
        }
    }
    return true;
}


// function to determine if the array is first increasing then decreasing
bool isIncreasingThenDecreasing(int arr[], int start, int end)
{
    int direction = -1;
    int numberOfDirectionsChanged = -1;
    if (start == end)
    {
        return true;
    }
    if (arr[start] > arr[start + 1])
        return false;
    for (int i = start; i < end; i++)
    {
        if (arr[i] > arr[i + 1] && direction == 1)
        {
            direction = -1;
            numberOfDirectionsChanged++;
        }
        else if (arr[i] < arr[i + 1] && direction == -1)
        {
            direction = 1;
            numberOfDirectionsChanged++;
        }
    }
    return numberOfDirectionsChanged <= 1;
}



vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries, int q)
{
    vector<bool> res;
    pair<int, int> p;
    for (int i = 0; i < q; i++)
    {
        p.first = queries[i].first;
        p.second = queries[i].second;
        if (isIncreasing(a, p.first, p.second))
        {
            res.push_back(true);
        }
        else if (isDecreasing(a, p.first, p.second))
        {
            res.push_back(true);
        }
        else if (isIncreasingThenDecreasing(a, p.first, p.second))
        {
            res.push_back(true);
        }
        else
        {
            res.push_back(false);
        }
    }
    return res;
}



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }
    vector<bool> res = processQueries(a, n, queries, q);
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
