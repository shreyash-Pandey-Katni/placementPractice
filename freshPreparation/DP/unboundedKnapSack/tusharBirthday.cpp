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

int unboundedKnapSack(vector<int> weights, vector<int> values, int capacity)
{

    int numberOfweights = weights.size();
    vector<vector<int>> dp(numberOfweights + 1, vector<int>(capacity + 1, -1));
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
            if(weights[i-1] <= j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-weights[i-1]] + values[i-1]);
            }
            else
            dp[i][j] = dp[i-1][j];
        }
        
    }
    return dp[numberOfweights][capacity];
    
}

int unboundedKnapSackRecursive(vector<int> )

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += unboundedKnapSack(B, C, A[i]);
    }
    return sum;    
}

int main()
{
    // Example usage
    vector<int> A = {4,6}; // Capacities
    vector<int> B = {1,3}; // Weights
    vector<int> C = {5,3}; // Values

    int result = solve(A, B, C);
    cout << "Total maximum value: " << result << endl;

    return 0;
}
