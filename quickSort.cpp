#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (i<j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {7, 72, 90, 21, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
