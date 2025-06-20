#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int max_path_sum(int A[], int B[], int l1, int l2)
{
    int sum1 = 0, sum2 = 0;
    int maxSum = 0;
    int i = 0, j = 0;
    while(i < l1 && j < l2){
        if(A[i] < B[j]){
            sum1 += A[i++];
        }
        else if (A[i] > B[j]){
            sum2 += B[j++];
        }
        else{
            maxSum += max(sum1, sum2) + A[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }
    while(i < l1){
        sum1 += A[i++];
    }
    while(j < l2){
        sum2 += B[j++];
    }
    maxSum += max(sum1, sum2);
    return maxSum;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    int A[m];
    int B[n];
    for(int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    cout << max_path_sum(A, B, m, n) << endl;
    return 0;
}
