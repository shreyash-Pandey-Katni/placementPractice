#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void rotateArr(int arr[], int d, int n)
{
    int i, j, k;
    for (i = 0; i < d; i++)
    {
        int temp = arr[0];
        for (j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    rotateArr(arr, d, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
