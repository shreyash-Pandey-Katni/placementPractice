#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> st;
    vector<long long> res;
    st.push(arr[0]);
    int next = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(arr[i]);
            continue;
        }
        next = arr[i];
        while (!st.empty() && st.top() < next)
        {
            res.push_back(next);
            st.pop();
        }
        st.push(next);
    }
    while (!st.empty())
    {
        res.push_back(-1);
        st.pop();
    }
    return res;
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
