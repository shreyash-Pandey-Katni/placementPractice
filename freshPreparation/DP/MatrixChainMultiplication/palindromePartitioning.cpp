#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// FIXME: this code is not most optimized code as per GFG

bool isPalindrome(string S, int i, int j, vector<vector<int>> &palindrome)
{
    if (palindrome[i][j] == 1)
        return true;
    while (i < j)
    {
        if (S[i] != S[j])
        {
            palindrome[i][j] = 0;
            return false;
        }
        i++;
        j--;
    }
    palindrome[i][j] = 1;
    return true;
}

/**
 * Calculates the minimum number of partitions required to make a given string palindrome.
 * 
 * @param S The input string
 * @param i The starting index of the substring
 * @param j The ending index of the substring
 * @param dp The memoization table for storing intermediate results
 * @param palindrome The table for storing palindrome information of substrings
 * @return The minimum number of partitions required to make the substring palindrome
 */
int solve(string S, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &palindrome)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (isPalindrome(S, i, j, palindrome))
    {
        dp[i][j] = 0;
        return 0;
    }
    int minVal = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = solve(S, i, k, dp, palindrome);
            dp[i][k] = left;
        }
        if (dp[k + 1][j] != -1)
        {
            right = dp[k + 1][j];
        }
        else
        {
            right = solve(S, k + 1, j, dp, palindrome);
            dp[k + 1][j] = right;
        }
        minVal = min(left + right + 1, minVal);
    }
    dp[i][j] = minVal;
    return minVal;
}

int palindromicPartition(string str)
{
    int length = str.size();
    vector<vector<int>> dp(length + 1, vector<int>(length + 1, -1));
    vector<vector<int>> palindrome(length + 1, vector<int>(length + 1, -1));
    return solve(str, 0, length - 1, dp, palindrome);
}

int main()
{
    string str = "aaabba";

    int result = palindromicPartition(str);

    cout << "Minimum number of partitions required: " << result << endl;

    return 0;
}
