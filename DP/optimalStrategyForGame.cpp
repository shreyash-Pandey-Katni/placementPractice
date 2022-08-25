#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
long long maximumAmount(int arr[], int n)
{
    int front = 0, back = n - 1;
    long long max_sum = 0;
    int i = 0;
    while(front<back)
    {
        if(i%2 == 0){
            if(arr[front] > arr[back]){
                max_sum += arr[front];
                front++;
            }
            else{
                max_sum += arr[back];
                back--;
            }
        }
        else {
            if(arr[front] > arr[back]){
                front++;
            }
            else{
                back--;
            }
        }
        i++;
    }
    return max_sum;
}