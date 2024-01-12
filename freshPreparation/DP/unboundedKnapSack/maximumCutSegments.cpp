#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    vector<int> weights = {x,y,z};
    sort(weights.begin(), weights.end());
    int capacity = n;
    vector<vector<int>> dp(weights.size()+1, vector<int>(capacity+1, 0));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0)
            dp[i][j] = INT_MIN + 1;
            else if (j == 0)
            {
                dp[i][j] = 0;
            }            
        }        
    }

    for (int i = 1; i < dp[0].size(); i++)
    {
        if(i%weights[0] == 0)
        dp[1][i] = i/weights[0];
        else {
            dp[1][i] = INT_MIN + 1;
        }
    }
    

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(weights[i-1] <= j){
                dp[i][j] = max(dp[i][j-weights[i-1]] +1, dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(dp[weights.size()][capacity] >0)
    return dp[weights.size()][capacity];
    return 0;
}

int main() {
    int n = 9999;
    int x = 94, y = 20, z = 244;

    int result = maximizeTheCuts(n, x, y, z);
    if (result != -1) {
        cout << "Maximum number of segments is " << result << endl;
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}