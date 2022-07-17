// A C++ recursive program to print all n-digit
// numbers whose sum of digits equals to given sum
#include <bits/stdc++.h>
using namespace std;

// Recursive function to print all n-digit numbers
// whose sum of digits equals to given sum

// n, sum --> value of inputs
// out --> output array
// index --> index of next digit to be filled in
//		 output array

bool recurse(string s, int i, long long prev, long long curr, long long &finalAns)
{
    if (i >= s.size())
    {
        return curr <= prev && prev - curr == 1;
    }
    if (curr <= prev && curr * 10 + s[i] - 48 <= prev)
    {
        if (recurse(s, i + 1, prev, curr * 10 + s[i] - 48, finalAns))
        {
            if(finalAns == 0){
                finalAns = curr;
            }
            return true;
        }
    }
    if (s[i] - 48 <= curr && prev - curr == 1)
    {
        return recurse(s, i + 1, curr, s[i] - 48, finalAns);
    }
    return false;
}

bool splitString(string s, long long &finalAns)
{
    long long n = s.size();
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return s[0] - s[1] == 1;
    }
    long long prev = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (i == n - 2 && prev > 100)
        {
            return false;
        }
        prev = prev * 10 + s[i] - 48;
        if (recurse(s, i + 2, prev, s[i + 1] - 48, finalAns))
        {
            return true;
        }
    }
    return false;
}

void findNDigitNumsUtil(int n, int sum, char *out,
                        int index, bool &flag, long long &finalAns)
{
    if (flag)
        return;
    // Base case
    if (index > n || sum < 0)
        return;

    // If number becomes N-digit
    // if sum of its digits is equal to given sum,
    // print it
    if (index == n && sum == 0 && splitString(out, finalAns))
    {
        out[index] = '\0';
        flag = true;
        return;
    }
    // Traverse through every digit. Note that
    // here we're considering leading 0's as digits
    for (int i = 0; i <= 9; i++)
    {
        // append current digit to number
        out[index] = i + '0';
        if (flag)
            return;
        // recurse for next digit with reduced sum
        findNDigitNumsUtil(n, sum - i, out, index + 1, flag, finalAns);
    }
}

// This is mainly a wrapper over findNDigitNumsUtil.
// It explicitly handles leading digit
void findNDigitNums(int n, int sum, bool &flag, long long &finalAns)
{
    // output array to store N-digit numbers
    char out[n + 1];

    // fill 1st position by every digit from 1 to 9 and
    // calls findNDigitNumsUtil() for remaining positions
    for (int i = 1; i <= 9; i++)
    {
        out[0] = i + '0';
        findNDigitNumsUtil(n, sum - i, out, 1, flag, finalAns);
    }
}

// Driver program
string solve(int S)
{
    int sum = S;
    bool flag = false;
    if(S/10 == 0){
        if(S==1){
            return "1";
        }
        else if(S%2 == 0){
            return "-1";
        }
        else {
            int res = (S - 1) / 2;
            return to_string(res);
        }
    }
    long long finalAns = 0;
    for (int i = 4; i < 100 && !flag; i += 2)
    {
        findNDigitNums(i, sum, flag, finalAns);
    }
    if(flag){
        return to_string(finalAns);
    }
}
