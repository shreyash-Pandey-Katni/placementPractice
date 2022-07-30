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
    unordered_set<int> s1(a, a + n);
    unordered_set<int> s2(b, b + m);
    int count = 0;
    for (auto i : s1)
    {
        if (s2.find(i) != s2.end())
        {
            count++;
        }
    }
    return count;
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
