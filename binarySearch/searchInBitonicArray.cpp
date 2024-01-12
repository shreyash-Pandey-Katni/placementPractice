#include<iostream>
#include<vector>
using namespace std;

int toppleIndex(vector<int> &A) {
    int length = A.size();
    for (int i=0;i<length-1;i++){
        if (A[i] > A[i+1]){
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> &A, int B, int low, int high){
    int mid = (low+high)/2;
    if (low>high) {
        return -1;
    }
    if (A[mid] == B){
        return mid;
    }
    else if (A[mid] > B){
        return binarySearch(A, B, low, mid-1);
    }
    else if(A[mid] < B)
    {
        return binarySearch(A, B, mid+1, high);
    }
    return -1;
    
}

int reverseBinarySearch(vector<int> &A, int B, int low, int high){
    int mid = (low+high)/2;
    if (low>high) {
        return -1;
    }
    if (A[mid] == B){
        return mid;
    }
    else if (A[mid] < B){
        return reverseBinarySearch(A, B, low, mid-1);
    }
    else
    {
        return reverseBinarySearch(A, B, mid+1, high);
    }
    
}


int solve(vector<int> &A, int B) {
    int toppleIndx = toppleIndex(A);
    vector<int> slicedA(A.begin()+toppleIndx+1, A.end());
    vector<int> incSlice(A.begin(), A.begin()+toppleIndx+1);
    int incIndex = binarySearch(incSlice, B,0, incSlice.size()-1);
    int decIndex = reverseBinarySearch(slicedA, B, 0, slicedA.size()-1);
    if (incIndex == -1 && decIndex == -1)
    return -1;
    else if (incIndex == -1)
    {
        return decIndex + incSlice.size();
    }
    else
    {
        return incIndex;
    }
    
    
    return 0;
}


int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
    int B = 12;
    cout<<solve(A, B);
}
