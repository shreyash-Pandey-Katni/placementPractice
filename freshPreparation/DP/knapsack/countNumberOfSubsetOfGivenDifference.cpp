#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>
#include <fstream>
#include <complex>
#include <regex>
#include <random>
#include <chrono>
#include <tuple>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <forward_list>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>
#include <valarray>
#include <thread>
#include <future>
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <shared_mutex>
#include <optional>
#include <variant>
#include <any>
#include <numbers>
#include <execution>
#include <span>
#include <ranges>
#include <compare>
#include <version>
#include <concepts>
#include <bit>
#include <source_location>
#include <stop_token>
#include <semaphore>
#include <barrier>
#include <latch>
#include <syncstream>
#include <filesystem>
#include <memory_resource>
#include <numbers>
#include <ranges>
#include <compare>
using namespace std;

int countNumberOfSubsetOfGivenDifference(int arr[], int n, int diff){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < sum+1; j++)
        {
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < sum+1; j++)
        {
            if(arr[i-1] <=j){
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int s1 = (sum-diff)/2;
    return dp[n][s1];            
}

int main() {
    // Test cases
    vector<tuple<vector<int>, int, int>> testCases = {
        {{1, 1, 2, 3}, 1, 3},
        {{1, 1, 2, 3}, 2, 2},
        {{1, 2, 3, 4, 5}, 1, 4},
        {{1, 2, 3, 4, 5}, 3, 3},
        {{1, 2, 3, 4, 5, 6}, 1, 5},
        {{1, 2, 3, 4, 5, 6}, 3, 4},
        {{1, 2, 3, 4, 5, 6, 7}, 1, 6},
        {{1, 2, 3, 4, 5, 6, 7}, 3, 5},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 0, 512},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 2, 252},
    };

    // Run test cases
    for (const auto& [values, diff, expected] : testCases) {
        int n = values.size();
        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = values[i];
        }
        int result = countNumberOfSubsetOfGivenDifference(arr, n, diff);
        cout << "Test " << (result == expected ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}