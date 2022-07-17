#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

string solve(int S)
{
    int sum = S;
    bool flag = false;
    if (S % 2 != 1)
    {
        return "-1";
    }
    unordered_map<int, int> countOfX;
    countOfX[1] = 1;
    countOfX[3] = 10;
    countOfX[5] = 2;
    countOfX[7] = 12;
    countOfX[9] = 4;
    countOfX[11] = 14;
    countOfX[13] = 6;
    countOfX[15] = 16;
    countOfX[17] = 8;
    if (countOfX.find(S) != countOfX.end())
    {
        return to_string(countOfX[S]);
    }
    else
    {
        return to_string((S - 17) / 2) + "8";
    }
    return "-1";
}
int main(int argc, char const *argv[])
{
    int S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}
