#include<iostream>
#include<vector>
using namespace std;
int countBits(int n){
    int count = 0;
    while(n){
        count++;
        n = n & (n-1);
    }
    return count;
}
int numberOfBitsToBeFlipped(int A, int B){
    return countBits(A^B);
}
int main(int argc, char const *argv[])
{
    int A,B;
    cin >> A >> B;
    cout << numberOfBitsToBeFlipped(A,B) << endl;
    return 0;
}