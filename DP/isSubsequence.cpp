#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    int indexS = 0;
    int indexT = 0;
    int sizeS = s.size();
    int sizeT = t.size();
    while (indexS < sizeS && indexT<sizeT){
        if(s.at(indexS) == t.at(indexT))
            indexS++;
        indexT++;
    }
    return indexS == sizeS;
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t) << endl;
    return 0;
}
