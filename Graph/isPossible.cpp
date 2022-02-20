#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int v, vector<bool>&visited, vector<int>adj[]){
    if(visited[v]==true)
        return false;
    visited[v]=true;
    for(int i=0;i<adj[v].size();i++)
    {
        if(visited[adj[v][i]]==false)
        {
            if(isCyclicUtil(adj[v][i],visited,adj))
                return true;
        }
        else if(visited[adj[v][i]]==true)
            return true;
    }
    return false;
}

bool isCyclic(int C, vector<int>adj[])
{
    vector<bool>visited(C,false);
    int i = 0;
    for (int i = 0; i < C; i++)
    {
        if(!visited[i])
        {
            if(isCyclicUtil(i,visited,adj))
            {
                return true;
            }
        }
    }
    return false;
}
bool isPossible(int N, vector<pair<int,int>>&prereuisites){
    vector<int>adj[N];
    for(int i=0;i<prereuisites.size();i++)
    {
        adj[prereuisites[i].second].push_back(prereuisites[i].first);
    }
    if(isCyclic(N,adj))
        return false;
    return true;
}