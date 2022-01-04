#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> s;
    vector<long long> result(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (!s.empty())
        {
            while (!s.empty() && arr[i] > s.top())
            {
                s.pop();
            }
        }
        result[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]);
    }
    return result;
}
int main(int argc, char const *argv[])
{
    int n = 4;
    vector<long long> arr = {11, 13, 21, 3};
    vector<long long> res = nextLargerElement(arr, n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
