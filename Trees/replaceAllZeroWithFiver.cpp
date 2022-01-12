#include<iostream>
#include<string>

using namespace std;
int convertFive(int n){
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            s[i] = '5';
        }
    }
    return stoi(s);
}