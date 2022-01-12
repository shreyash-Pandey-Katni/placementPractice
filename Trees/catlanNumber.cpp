#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, unsigned long long int> map;
unsigned long long int catlanNumber(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (map.find(n) != map.end())
    {
        return map[n];
    }
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
    map[2] = 2;
    return catlanNumber(N);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << numTrees(i) << endl;
    }
    return 0;
}
