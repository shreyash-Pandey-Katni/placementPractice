#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int longestCommonSubstr(string X, string Y, int n, int m)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i =0;i<dp.size();i++){
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
        }
        
    }
    int maxLength = INT_MIN;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
                maxLength = max(dp[i][j], maxLength);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    if(maxLength != INT_MIN)
    return maxLength;
    return 0;
    
}

int main() {
    string X = "ABC";
    string Y = "BABC";

    int n = X.size();
    int m = Y.size();

    cout << "Length of Longest Common Substring is " << longestCommonSubstr(X, Y, n, m) << endl;

    return 0;
}