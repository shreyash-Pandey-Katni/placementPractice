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

int lcs(string X, string Y, int n, int m){
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
        
    }
    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
    }
    return dp[n][m];
    
    
}

int minDeletions(string str, int n) { 
    string revString = str;
    reverse(revString.begin(), revString.end());
    return n-lcs(str, revString, n, n);
} 

int main() {
    string str = "aebcbda";
    int n = str.length();
    int minDeletionsCount = minDeletions(str, n);
    cout << "Minimum number of deletions required: " << minDeletionsCount << endl;
    return 0;
}
