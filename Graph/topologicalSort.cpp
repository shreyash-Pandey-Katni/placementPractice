#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> st;

void dfs(int V,vector<bool>&visited, vector<int>adj[])
{
    visited[V] = true;
    for(int i=0;i<adj[V].size();i++)
    {
        if(!visited[adj[V][i]])
        {
            dfs(adj[V][i],visited,adj);
        }
    }
    st.push(V);
}

vector<int> topoSort(int V, vector<int>adj[]){
    
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj);
        }
    }
    vector<int>res;
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}