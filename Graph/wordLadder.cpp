#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int numberOfDifferentCharacters(string s1, string s2)
{
    int count = 0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i] != s2[i])
        {
            count++;
        }
    }
    return count;
}
int res = INT_MAX;

bool isMatching(string s1, string s2){
    if (s1.length() != s2.length())
        return false;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}

void dfs(int pos, vector<bool>&visited, string targetWord, vector<string>&wordList, int depth){
    visited[pos] = true;
    if(isMatching(targetWord,wordList[pos])){
        res = min(res, depth);
        visited[pos] = false;
        return;
    }
    for(int i=0;i<wordList.size();i++)
    {
        if(!visited[i] && numberOfDifferentCharacters(wordList[pos], wordList[i]) == 1)
        {
            dfs(i, visited, targetWord, wordList, depth+1);
        }
    }
    visited[pos] = false;
}

int wordLadderLength(string startWord, string targetWord, vector<string>&wordList){
    int n = wordList.size();
    vector<bool> visited(n, false);
    int depth = 1;
    for (int i = 0; i < n; i++)
    {
        if(isMatching(startWord, wordList[i]))
        {
            visited[i] = true;
        }
    }
    
    for (int i = 0; i < wordList.size(); i++)
    {
        if(numberOfDifferentCharacters(startWord, wordList[i]) == 1)
        {
            dfs(i, visited, targetWord, wordList, depth+1);
        }
    }
    
    return res;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<string>wordList(n);
    for (int i = 0; i < n; i++)
    {
        cin>>wordList[i];
    }
    string startWord, targetWord;
    cin>>startWord>>targetWord;
    cout<<wordLadderLength(startWord, targetWord, wordList);
    return 0;
}
