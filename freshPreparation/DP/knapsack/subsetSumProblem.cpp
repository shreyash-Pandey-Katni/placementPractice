#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Checks if there exists a subset of given values that adds up to the given sum.
 * 
 * @param values An array of integers representing the values.
 * @param n The number of elements in the array.
 * @param sum The target sum.
 * @return true If there exists a subset that adds up to the sum.
 * @return false Otherwise.
 */
bool subsetSumProblem(int values[], int n, int sum) {
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            if (j == 0) {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (values[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - values[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][sum];
}

int main() {
    // Test cases
    vector<tuple<vector<int>, int, bool>> testCases = {
        {{1, 2, 3}, 6, true},
        {{1, 2, 3}, 7, false},
        {{1, 2, 3, 4}, 10, true},
        {{1, 2, 3, 4}, 11, false},
        {{1, 2, 3, 4, 5}, 15, true},
        {{1, 2, 3, 4, 5}, 16, false},
        {{1, 2, 3, 4, 5, 6}, 21, true},
        {{1, 2, 3, 4, 5, 6}, 22, false},
        {{1, 2, 3, 4, 5, 6, 7}, 28, true},
        {{1, 2, 3, 4, 5, 6, 7}, 29, false},
    };

    // Run test cases
    for (const auto& [values, sum, expected] : testCases) {
        int n = values.size();
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = values[i];
        }
        bool result = subsetSumProblem(arr.data(), n, sum);
        cout << "Test " << (result == expected ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}