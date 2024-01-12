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

int countOfSubsetOfAGivenSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    // Test cases
    vector<tuple<vector<int>, int, int>> testCases = {
        {{1, 2, 3}, 4, 3},
        {{1, 2, 3}, 5, 2},
        {{1, 2, 3, 4, 5}, 10, 3},
        {{1, 2, 3, 4, 5}, 15, 1},
        {{1, 2, 3, 4, 5, 6}, 21, 1},
        {{1, 2, 3, 4, 5, 6}, 22, 0},
        {{1, 2, 3, 4, 5, 6, 7}, 28, 1},
        {{1, 2, 3, 4, 5, 6, 7}, 29, 0},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 5, 252},
        {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 10, 1},
    };

    // Run test cases
    for (const auto& [values, sum, expected] : testCases) {
        int n = values.size();
        vector<int> arr = values;
        int result = countOfSubsetOfAGivenSum(arr.data(), n, sum);
        cout << "Test " << (result == expected ? "PASSED" : "FAILED") << endl;
    }

    return 0;
}