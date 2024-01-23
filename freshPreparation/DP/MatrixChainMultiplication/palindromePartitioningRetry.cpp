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

bool isPalindrome(string A, int i, int j)
{
    // int i = 0;
    // int j = A.size()/2;
    while (i < j)
    {
        if (A[i++] != A[j--])
            return false;
    }
    return true;
}

int palindrome(int i, int j, string A, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (isPalindrome(A, i, j))
    {
        dp[i][j] = 0;
        return 0;
    }

    int minVal = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int left = 0;
        int right = 0;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
            left = palindrome(i, k, A, dp);
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = palindrome(k + 1, j, A, dp);
        minVal = min(minVal, left + right+1);
    }
    dp[i][j] = minVal;
    return dp[i][j];
}

int minCut(string A)
{
    int n = A.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return palindrome(0, n - 1, A, dp);
}

int main()
{
    string input = "aab";
    int result = minCut(input);
    cout << "Minimum number of cuts required: " << result << endl;
    return 0;
}
