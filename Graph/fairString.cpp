#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool isFairString(string S)
{
    bool type1 = true;
    bool type2 = true;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == S[i + 1])
        {
            type1 = false;
            break;
        }
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == S[i + 2])
        {
            type2 = false;
            break;
        }
    }
    return type1 && type2;
}

int convertStringToType2(string S, int cost[]){
    string res = "";
    int cost_res = 0;
    for (int i = 0; i < S.size(); i += 2)
    {
        if(S[i] == S[i+1]){
            res += S[i];
            res += S[i+1];
        }
        else{
            if(i == 0){
            if(cost[i] < cost[i+1]){
                res += S[i];
                res += S[i];
                cost_res += cost[i];
            }
            else{
                res += S[i+1];
                res += S[i+1];
                cost_res += cost[i+1];
            }
            }
            else{
                if(cost[i] < cost[i+1] && S[i] != S[i-1]){
                    res += S[i];
                    res += S[i];
                    cost_res += cost[i];
                }
                else{
                    res += S[i+1];
                    res += S[i+1];
                    cost_res += cost[i+1];
                }
            }
        }
    }
    return cost_res;
}

int convertStringToType1(string S, int cost[])
{
    string res = "";
    int temp1 = 0;
    bool type1 = S[0] == '0';
    for (int i = 0; i < S.size()-1; i++)
    {
        if (S[i] == S[i + 1])
        {
            S[i + 1] = S[i + 1] == '0' ? '1' : '0';
            temp1 += cost[i + 1];
        }
        else
        {
            res += S[i];
        }
    }
    int temp = temp1;
    temp1 = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == S[i + 1])
        {
            S[i] = S[i] == '0' ? '1' : '0';
            temp1 += cost[i];
        }
        else
        {
            res += S[i];
        }
    }
    return temp>temp1?temp:temp1;
}

int costToConvertToFairString(int N, string S, int cost[])
{
    int costToConvert = 0;
    if (isFairString(S))
    {
        return 0;
    }
    int type1 = convertStringToType1(S, cost);
    int type2 = convertStringToType2(S, cost);
    return type1>type2?type1:type2;
}