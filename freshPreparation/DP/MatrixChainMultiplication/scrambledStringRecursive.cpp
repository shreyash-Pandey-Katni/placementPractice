#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

bool solveRecursive(string A, string B) {
    int n = A.size();
    if (A.compare(B) == 0 && A.size() != 0)
        return true;
    if (A.size() == 0)
        return false;

    for (int i = 1; i < A.size(); i++) {
        if (
            (
                solveRecursive(A.substr(0, i), B.substr(n - i, i)) && 
                solveRecursive(A.substr(n - i, i), B.substr(0, i))
            ) 
            ||
            (
                solveRecursive(A.substr(0, i), B.substr(0, i)) && 
                solveRecursive(A.substr(i, n - i), B.substr(i, n - i))
            )
            )
            return true;
    }
    return false;
}

bool solve(string A, string B, vector<vector<vector<int>>> &dp) {
    int n = A.size();
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            for (int j = 0; j <= n - len; j++) {
                if (len == 1) {
                    dp[i][j][len] = (A[i] == B[j]);
                } else {
                    for (int k = 1; k < len && dp[i][j][len] == false; k++) {
                        dp[i][j][len] = (dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                                        (dp[i][j + len - k][k] && dp[i + k][j][len - k]);
                    }
                }
            }
        }
    }
    return dp[0][0][n];
}

int isScramble(const string A, const string B) {
    int n = A.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1, false)));
    return solveRecursive(A, B);
}

int main() {
    string A = "qmfcwwzbqkf";
    string B = "wfcmbzwqqkf";

    auto start = chrono::high_resolution_clock::now(); // Start measuring time

    int result = isScramble(A, B);

    auto end = chrono::high_resolution_clock::now();                          // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Calculate duration in microseconds

    cout << "IsScramble: " << result << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl; // Print the time taken

    return 0;
}
