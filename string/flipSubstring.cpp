#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
// write a function to convert binary string to decimal number
int binaryToDecimal(string binary)
{
    int decimal = 0;
    for (int i = 0; i < binary.length(); i++)
    {
        decimal += (binary[i] - '0') * pow(2, binary.length() - i - 1);
    }
    return decimal;
}
// write a function to extract number from binary string
int extractNumber(string binary){
    int number = 0;
    for (int i = 0;i<binary.length();i++){
        number += (binary[i]-'0')*pow(10,binary.length()-i-1);
    }
    return number;
}
int countFlips(int a, int b)
{

    // initially flips is equal to 0
    int flips = 0;

    // & each bits of a && b with 1
    // and store them if t1 and t2
    // if t1 != t2 then we will flip that bit

    while (a > 0 || b > 0)
    {

        int t1 = (a & 1);
        int t2 = (b & 1);

        if (t1 != t2)
        {
            flips++;
        }
        // right shifting a and b
        a >>= 1;
        b >>= 1;
    }

    return flips;
}
int solve(string A, int B){
    int number = binaryToDecimal(A);
    int convertedNumber = extractNumber(A);
    int flips = __builtin_popcount(number ^ convertedNumber);
    return flips;
}
int main(int argc, char const *argv[])
{
    string A;
    cin >> A;
    int B = A.length();
    cout << solve(A,B) << endl;
    return 0;
}
