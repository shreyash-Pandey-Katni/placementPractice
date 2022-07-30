#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    unordered_map<int,int>inDegree;
    unordered_map<int, int> outDegree;
    vector<int>res;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(inDegree.find(adj[i][j])==inDegree.end())
            {
                inDegree[adj[i][j]]=0;
            }
            inDegree[adj[i][j]]++;
            if(outDegree.find(i)==outDegree.end())
            {
                outDegree[i]=0;
            }
            outDegree[i]++;
        }
    }
    int count=0;
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for(int i=0;i<adj[curr].size();i++)
        {
            inDegree[adj[curr][i]]--;
            if(inDegree[adj[curr][i]]==0)
            {
                q.push(adj[curr][i]);
            }
        }
    }
    if(res.size()!=V)
    {
        return vector<int>();
    }
    return res;
}