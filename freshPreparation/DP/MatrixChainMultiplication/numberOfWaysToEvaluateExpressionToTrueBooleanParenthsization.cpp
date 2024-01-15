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

int solve(string S, int i, int j, bool exprValue, vector<vector<vector<int>>> &dp){
    if(i>j)
    return false;
    if(i==j){
        if(exprValue == true)
        return S[i] == 'T';
        else
        return S[i] == 'F';
    }
    if (dp[i][j][exprValue] != -1)
    return dp[i][j][exprValue];
    
    int retVal = 0;
    for (int k = i+1; k < j; k+=2)
    {
        int leftTrue = solve(S, i, k-1, true, dp);
        int leftFalse = solve(S, i, k-1, false, dp);
        int rightTrue = solve(S, k+1, j, true, dp);
        int rightFalse = solve(S, k+1, j, false, dp);
        if (exprValue)
        {
            if(S[k] == '^')
            retVal += leftTrue*rightFalse + leftFalse*rightTrue;
            else if (S[k] == '&')
            {
                retVal += leftTrue*rightTrue;
            }
            else {
                retVal += leftTrue*(rightTrue+ rightFalse)+ leftFalse*rightTrue;
            }
            
        }
        else {
            if (S[k] == '^')
            {
                retVal += leftTrue*rightTrue + leftFalse*rightFalse;
            }
            else if (S[k] == '&')
            {
                retVal += leftFalse*(rightTrue+rightFalse)+ leftTrue*rightFalse;
            }
            else {
                retVal += leftFalse * rightFalse;
            }            
            
        }
        
    }
    dp[i][j][exprValue] = retVal;
    return retVal;
    
}

int countWays(int N, string S)
{
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(N+1, vector<int>(2, -1)));
    return solve(S, 0, N-1, true, dp);
}

int main(int argc, char const *argv[])
{
    string S = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    int n = S.size();
    cout<<"output of count ways is :"<<countWays(n, S)<<endl;
    return 0;
}
