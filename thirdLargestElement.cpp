#include<iostream>
#include<string>
using namespace std;
int thirdLargest(int arr[], int n){
    int largest = arr[0];
    int secondLargest = arr[0];
    int thirdLargest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest)
        {
            thirdLargest = secondLargest;
            secondLargest = arr[i];
        }
        else if (arr[i] > thirdLargest)
        {
            thirdLargest = arr[i];
        }
    }
    return thirdLargest;
}