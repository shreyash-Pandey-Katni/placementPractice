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

// FIXME: switch only at one point

int max_path_sum(int A[], int B[], int l1, int l2)
{
    vector<int> commonElements;
    int i = l1-1, j=l2-1, result = 0, sum1= 0, sum2=0;
    while(i>=0 && j>=0){
        if(A[i]>B[j]){
            sum1 += A[i];
            i--;
        } else if(A[i]<B[j]) {
            sum2 += B[j];
            j--;
        } else {
            result += max(sum1, sum2) + A[i];
            sum1 = 0;
            sum2 = 0;
            i--;
            j--;
        }
    }
    while(i>=0)
    sum1 += A[i--];
    while(j>=0)
    sum2 += B[j--];
    result += max(sum1, sum2);
    return result;
}

int main() {
    int A[] = {2, 3, 7, 10, 12, 15, 30, 34};
    int B[] = {1, 5, 7, 8, 10, 15, 16, 19};
    int l1 = sizeof(A) / sizeof(A[0]);
    int l2 = sizeof(B) / sizeof(B[0]);

    cout << "Maximum sum path is " << max_path_sum(A, B, l1, l2) << endl;

    return 0;
}