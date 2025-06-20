#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int trailingZeroes(int N)
{
    if(N<0){
        return -1;
    }
    int count=0;
    for(int i=5;N/i>0;i*=5){
        count+=N/i;
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int N;
    cout << "Enter the number: ";
    cin >> N;
    int numberOfZeroes = trailingZeroes(N);
    cout << "The number of trailing zeroes is: " << numberOfZeroes;
    return 0;
}
