#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int convertFive(int n){
    string temp = to_string(n);
    for (int i = 0; i < temp.length(); i++)
    {
        if (temp[i] == '0'){
            temp[i] = '5';
        }
    }
    return stoi(temp);
}

int main(int argc, char const *argv[])
{
    int n = 1554;
    cout<<convertFive(n)<<endl;
    return 0;
}
