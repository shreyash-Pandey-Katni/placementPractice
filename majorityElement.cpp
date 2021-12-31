#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
int majorityElement(const vector<int> &A){
    unordered_map<int, int> map;
    int target = A.size() / 2;
    for (int i = 0; i < A.size(); i++)
    {
        if (map.find(A[i]) != map.end())
        {
            map[A[i]] += 1;
        }
        else
        {
            map[A[i]] = 1;
        }
        if (map[A[i]] > target)
        {
            return A[i];
        }
    }
    return A[0];
}
int main(int argc, char const *argv[])
{
    int numberOfElements;
    cin >> numberOfElements;
    vector<int> A(numberOfElements);
    for (int i = 0; i < numberOfElements; i++)
    {
        cin >> A[i];
    }
    cout << majorityElement(A) << endl;
    return 0;
}
