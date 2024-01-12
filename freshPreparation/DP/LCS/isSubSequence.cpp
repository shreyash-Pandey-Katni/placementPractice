#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            
        }
        
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m] == t.size();
    
    
}

int main() {
    string s = "abc";
    string t = "ahbgdc";
    
    bool result = isSubsequence(s, t);
    
    if (result) {
        cout << "s is a subsequence of t" << endl;
    } else {
        cout << "s is not a subsequence of t" << endl;
    }
    
    return 0;
}
