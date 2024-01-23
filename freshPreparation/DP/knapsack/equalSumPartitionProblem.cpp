#include <iostream>
#include <vector>
using namespace std;

bool subsetSumProblem(int values[], int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (values[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - values[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(dp[i][j])
            count++;
        }
        
    }
    cout<<count<<endl;
    return dp[n][sum];
}

bool equalSumPartition(int values[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += values[i];
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    return subsetSumProblem(values, n, sum / 2);
}

/**
 * @brief The main function that runs the test cases for the equalSumPartition problem.
 * 
 * @return int Returns 0 upon successful execution.
 */
#include <tuple> // Include the <tuple> header

#include <iostream>
#include <vector>
#include <tuple> // Include the <tuple> header
using namespace std;

int main() {
    // Test cases
    vector<tuple<vector<int>, bool>> testCases = {
        tuple<vector<int>, bool>(vector<int>{1, 5, 11, 5}, true), // Use tuple constructor to create the tuple
        tuple<vector<int>, bool>(vector<int>{1, 2, 3, 5}, false),
        tuple<vector<int>, bool>(vector<int>{1, 2, 3, 4, 5, 6, 7}, true),
        tuple<vector<int>, bool>(vector<int>{1, 2, 3, 4, 5, 6}, false),
        tuple<vector<int>, bool>(vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, true),
        tuple<vector<int>, bool>(vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1}, false),
        tuple<vector<int>, bool>(vector<int>{100, 200, 300, 400, 500}, false),
        tuple<vector<int>, bool>(vector<int>{100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}, true),
        tuple<vector<int>, bool>(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, true),
        tuple<vector<int>, bool>(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, false),
    };

    // Run test cases
    for (const auto& testCase : testCases) { // Iterate over the testCases vector directly
        const vector<int>& values = get<0>(testCase); // Access the values using get<0>
        bool expected = get<1>(testCase); // Access the expected value using get<1>
        int n = values.size();
        vector<int> arr = values;
        bool result = equalSumPartition(arr.data(), n);
        cout << "Test " << (result == expected ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}