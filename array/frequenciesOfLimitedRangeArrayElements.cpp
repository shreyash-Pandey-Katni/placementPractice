#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void frequencyCount(vector<int> &arr, int N, int P)
{
    vector<int> result(P+1, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0 && arr[i] <= N)
            result[arr[i]]++;
    }
    for (int i = 0; i < N+1;i++){
        arr[i] = result[i];
    }
}
int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i = 0;i<N;i++)
    {
        cin>>arr[i];
    }
    int P;
    cin>>P;
    frequencyCount(arr, N, P);
    return 0;
}
