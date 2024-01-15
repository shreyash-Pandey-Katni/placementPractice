#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solve(int arr[], int i, int j){
    if(i>=j)
    return 0;
    int minVal = INT_MAX;
    for (int k = i; k < j; k++)
    {
        minVal = min(solve(arr, i, k)+ solve(arr, k+1, j)+ arr[i-1]*arr[k]*arr[j], minVal);
    }
    return minVal;
    
}

int matrixMultiplicationRecursive(int N, int arr[]){
    return solve(arr, 1, N-1);
}

int main() {
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};
    
    int result = matrixMultiplicationRecursive(N, arr);
    
    cout << "Minimum number of multiplications required: " << result << endl;
    
    return 0;
}
