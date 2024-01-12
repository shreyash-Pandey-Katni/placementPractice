#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int largestRepeatingSubsequence(string X){
    string Y = X;
    int n = X.size(), m = Y.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
        
    }

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(X[i-1] == Y[j-1] && i!=j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m];
}

int main() {
    string X = "AABEBCDD";
    int result = largestRepeatingSubsequence(X);
    cout << "Length of the largest repeating subsequence: " << result << endl;
    return 0;
}
