#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcsDP(string X, string Y, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i =0;i<dp.size();i++){
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
        
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
    
}

int main()
{
    string X = "ECBDEBD";
    string Y = "BCACCBDA";

    int n = X.size();
    int m = Y.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << "Length of LCS is " << lcsDP(X, Y, n, m) << endl;

    return 0;
}