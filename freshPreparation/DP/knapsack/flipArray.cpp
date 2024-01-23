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

int targetSum(const vector<int> &A)
{
    vector<int> weights = A;
    int capacity = 0;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        capacity += A[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));

    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < dp[0].size(); j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(weights[i-1] <= j)
            dp[i][j] = max(dp[i-1][j-weights[i-1]]+1, dp[i-1][j]);
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    // if(capacity%2 == 1)
    // capacity++;
    int j = capacity/2+1, i = capacity/2;
    while(i>=0 and j<=capacity){
        if(dp[n][i] != -1 && dp[n][j] != -1){
            if(dp[n][i] > dp[n][j])
            return dp[n][i];
            else
            return dp[n][j];
        }
        else if (dp[n][i] != -1)
        {
            return dp[n][i];
        }
        else if (dp[n][j] != -1)
        {
            return dp[n][j];
        }
        i--;
        j++;        
    }
    // for (int i = capacity/2; i >=0; i++)
    // {
    //     if(dp[n][i] != -1){
    //         return dp[n][i];
    //     }
    // }
    // return -1;
}

int solve(const vector<int> &A) {
    int n = A.size();
    vector<int> B = A;
    sort(B.begin(), B.end());
    int ans = targetSum(B);
    if(n-ans<=n/2)
    return n-ans;
    return ans;
}

int main() {
    int result = 0;
    vector<int> A = {3, 3, 7, 10, 2, 1, 5, 3, 8, 5, 1, 4, 3, 9, 1, 4, 8, 1, 1, 4, 5, 10, 3, 8, 5, 3, 6, 3, 5, 5, 4, 9, 7, 1, 9, 10, 3, 3, 4, 2, 9, 4, 5, 3, 3, 5, 6, 2, 8, 6, 8, 2, 7, 10, 9, 2, 4, 4, 4, 8, 10, 9, 7, 8, 1, 5, 9, 5, 9, 2, 7, 9, 6, 3, 2, 10, 10, 7, 1, 7, 5, 10, 10, 1, 9, 10, 4, 2, 5, 9, 10};
    // result = solve(A);
    // cout << "Result: " << result << endl;
    A = {69, 17, 47, 50, 38, 22, 60, 4, 88, 22};
    result = solve(A);
    cout<< "Result: " << result <<endl;
    return 0;
}
