#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
void segragate012(int arr[], int N){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            count0++;
        }
        else if (arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    int i = 0;
    while (count0--)
    {
        arr[i++] = 0;
    }
    while (count1--)
    {
        arr[i++] = 1;
    }
    while (count2--)
    {
        arr[i++] = 2;
    }
}