#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    auto const subArrayOne = m - l + 1;
    auto *leftArray = new int[subArrayOne];
    auto const subArrayTwo = r - l;
    auto *rightArray = new int[subArrayTwo];
    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = arr[l + i];
    }
    for (int i = 0; i < subArrayTwo; i++)
    {
        rightArray[i] = arr[m + 1 + i];
    }
    auto indexOfSubArrayOne = 0;
    auto indexOfSubArrayTwo = 0;
    int indexOfMergedArray = l;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo && indexOfMergedArray < r)
    {
        if (leftArray[indexOfSubArrayOne] < rightArray[indexOfSubArrayTwo])
        {
            arr[indexOfMergedArray++] = leftArray[indexOfSubArrayOne++];
        }
        else
        {
            arr[indexOfMergedArray++] = rightArray[indexOfSubArrayTwo++];
        }
    }
    while (indexOfSubArrayOne < subArrayOne)
    {
        arr[indexOfMergedArray++] = leftArray[indexOfSubArrayOne++];
    }
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        arr[indexOfMergedArray++] = rightArray[indexOfSubArrayTwo++];
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}