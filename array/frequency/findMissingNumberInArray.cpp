#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MissingNumber(vector<int> &array, int n)
{
    vector<int> temp(n+1,1);
    for( int i=0;i<n-1;i++)
    {
        temp[array[i]]=0;
    }
    for(int i=1;i<n+1;i++)
    {
        if(temp[i]==1)
        {
            return i;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> array;
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        array.push_back(temp);
    }
    int missingNumber=MissingNumber(array,n);
    cout<<"The missing number is: "<<missingNumber;
    return 0;
}
