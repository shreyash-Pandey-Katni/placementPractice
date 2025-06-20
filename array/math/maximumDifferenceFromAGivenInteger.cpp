#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int solve(int N, int a, vector<int> x){
    vector<int> diff;
    int maxDiff = INT_MIN;
    int secondMaxDiff = INT_MIN;
    for(int i=0;i<N;i++){
        int tempDiff = abs(x[i]-a);
        diff.push_back(tempDiff);
        if(tempDiff > maxDiff){
            secondMaxDiff = maxDiff;
            maxDiff = tempDiff;
        }
        else if(tempDiff > secondMaxDiff){
            secondMaxDiff = tempDiff;
        }
    }
    return maxDiff + secondMaxDiff;
}

int main(int argc, char const *argv[])
{
    int N;
    cin>>N;
    vector<int> x(N);
    int a;
    cin>>a;
    for(int i=0;i<N;i++){
        cin>>x[i];
    }
    cout<<solve(N,a,x);
    return 0;
}
