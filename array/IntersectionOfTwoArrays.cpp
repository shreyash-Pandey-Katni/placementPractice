#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int deleteDuplicatesFromArray(int arr[], int n)
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (arr[i] != arr[i + 1])
        {
            arr[j] = arr[i];
            j++;
        }
        i++;
    }
    return j;
}

int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    unordered_set<int> setA;
    int countOfCommonElements = 0;
    unordered_set<int> commonElements;
    n = deleteDuplicatesFromArray(a, n);
    m = deleteDuplicatesFromArray(b, m);
    if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            setA.insert(b[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (setA.find(a[i]) != setA.end())
            {
                countOfCommonElements++;
                commonElements.insert(b[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            setA.insert(a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            if (setA.find(b[i]) != setA.end())
            {
                countOfCommonElements++;
                commonElements.insert(b[i]);
            }
        }
    }
    return commonElements.size();
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << NumberofElementsInIntersection(a, b, n, m) << endl;
    return 0;
}
