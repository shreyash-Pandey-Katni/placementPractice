#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

int catalanNumber(int n)
{
    if (n == 0)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalanNumber(i) * catalanNumber(n - i - 1);
    }
    return res;
}

void generateParenthesisHelper(int n, int open, int close, string str, vector<string> &res)
{
    if (open == n && close == n)
    {
        res.push_back(str);
        return;
    }
    if (open < n)
    {
        generateParenthesisHelper(n, open + 1, close, str + '(', res);
    }
    if (close < open)
    {
        generateParenthesisHelper(n, open, close + 1, str + ')', res);
    }
}

vector<string> generateParenthesis(int n)
{
    int numberOfParenthesis = catalanNumber(n);
    vector<string> res;
    if (n == 0)
        return res;
    generateParenthesisHelper(n, 0, 0, "", res);
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> res = generateParenthesis(n);
    for (auto s : res)
    {
        cout << s << endl;
    }
    return 0;
}
