#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int makeProductOne(int arr[], int N)
{
    int steps = 0;
    int zero_count = 0;
    int neg_count = 0;
    for(int i=0;i<N;i++)
    {
        if(arr[i]==0)
        {
            zero_count++;
        }
        else if(arr[i]<0)
        {
            steps+= abs(arr[i])-1;
            neg_count++;
        }
        else{
            steps+=arr[i]-1;
        }
    }
    if (neg_count%2!=0 && zero_count==0)
    {
        steps += 2;
    }
    steps += zero_count;
    return steps;
}