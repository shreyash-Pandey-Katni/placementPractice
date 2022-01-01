#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
int minPoints(vector<vector<int>> points, int M, int N)
{
    int dp[M][N] = {0};
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = -1+points[i][j];
            }
            else if(i==0)
            {
                dp[i][j] = dp[i][j-1] + points[i][j];
            }
            else if(j==0)
            {
                dp[i][j] = dp[i-1][j] + points[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + points[i][j];
            }
        }
    }
    return dp[M-1][N-1];
}