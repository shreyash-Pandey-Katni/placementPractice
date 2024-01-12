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

vector<int> removeDuplicate(vector<int> &arr, int n)
{
    map<int, int> listOfUniqueElements;
    vector<int> result;
    for(int i =0;i<n;i++){
        if(listOfUniqueElements.find(arr[i]) == listOfUniqueElements.end()){
            listOfUniqueElements[arr[i]] = 1;
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 5, 5, 11, 7, 7, 11, 11};
    int n = arr.size();

    cout << "Original array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    vector<int> result = removeDuplicate(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}