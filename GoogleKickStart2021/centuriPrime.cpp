#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
unordered_map<char, string> mp;

string ruledBy(string planetName){
    int size = planetName.size();
    if(mp.find(planetName[size-1]) == mp.end())
        return "Bob";
    else
        return mp[planetName[size-1]];
}
int main(int argc, char const *argv[])
{
    mp['A'] = "Alice";
    mp['E'] = "Alice";
    mp['I'] = "Alice";
    mp['O'] = "Alice";
    mp['U'] = "Alice";
    mp['a'] = "Alice";
    mp['e'] = "Alice";
    mp['i'] = "Alice";
    mp['o'] = "Alice";
    mp['u'] = "Alice";
    mp['y'] = "nothing";
    int n;
    cin >> n;
    vector<string> planets(n);
    for (int i = 0; i < n; i++)
    {
        cin >> planets[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"Case #"<<i+1<<": "<<planets[i]<< " is ruled by "<<ruledBy(planets[i])<<"."<<endl;
    }
    return 0;
}
