#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
vector<int> countBits(int n)
{
    vector<int> res(n+1);
    res[0] = 0;
    for(int i=1;i<=n;i++){
        res[i] = res[i>>1] + (i&1);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> res = countBits(n);
    for(int i=0;i<=n;i++){
        cout << res[i] << " ";
    }
    return 0;
}
