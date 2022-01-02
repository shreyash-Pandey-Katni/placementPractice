#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
#define ll long long int
int minPoints(vector<vector<int>> points, int M, int N)
{
    int dp[M][N] = {0};
    dp[M-1][N-1] = points[M-1][N-1] >0 ? 1 : abs(points[M-1][N-1])+1;
    for(int i=M-2;i>=0;i--){
        dp[i][N-1] = max(dp[i+1][N-1] - points[i][N-1],1);
    }
    for(int i=N-2;i>=0;i--){
        dp[M-1][i] = max(dp[M-1][i+1] - points[M-1][i] ,1);
    }
    for(int i=M-2;i>=0;i--){
        for(int j=N-2;j>=0;j--){
            dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])-points[i][j],1);
        }
    }
    return dp[0][0];
}
int main(int argc, char const *argv[])
{
    int M = 3, N = 3;
    vector<vector<int>> points = {{-2,-3,3},{-5,-10,1},{10,30,-5}};
    cout<<minPoints(points,M,N)<<endl;
    return 0;
}
