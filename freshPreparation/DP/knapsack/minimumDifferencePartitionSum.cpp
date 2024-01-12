#include <iostream>
#include <vector>
using namespace std;

int minimumDifferencePartitionSum(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for(int i = 0;i<n+1; i++){
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0){
                dp[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i = sum/2;i>=0;i--){
        if(dp[n][i]){
            return sum-2*i;
        }
    }
}

/**
 * @brief Entry point of the program.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    // Test cases
    vector<tuple<vector<int>, int>> testCases = {
        {{1, 6}, 5},
        {{3, 1, 4, 2, 2, 1, 1, 2}, 0},
        {{1, 2, 3, 9}, 3},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 0},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 1},
        {{100, 200, 300, 400, 500}, 100},
        {{100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}, 50},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 1},
    };

    // Run test cases
    for (const auto& [values, expected] : testCases) {
        int n = values.size();
        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = values[i];
        }
        int result = minimumDifferencePartitionSum(arr, n);
        cout << "Test " << (result == expected ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}