#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<unsigned long long int, int> map;
unordered_map<int, int> memo;
int factorial(int n)
{
    if (n == 0)
        return 1;
    if (memo.find(n) != memo.end())
        return memo[n];
    int result = n * factorial(n - 1);
    memo[n] = result;
    return result;
}
unsigned long long int catlanNumber(int n)
{
    if (n == 0)
        return 1;
    if (map.find(n) != map.end())
        return map[n];
    unsigned long long int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += catlanNumber(i) * catlanNumber(n - i - 1);
    }
    map[n] = result;
    return result;
}
unsigned long long int numTrees(int N)
{
    map[1] = 1;
    memo[0] = 1;
    map[2] = 2;
    memo[1] = 1;
    return catlanNumber(N);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
    return 0;
}
