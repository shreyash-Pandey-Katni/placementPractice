#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
unordered_map<int, bool> visited;
vector<int> ans;
void dfs(int V, vector<int> adj[]){
    visited[V] = true;
    ans.push_back(V);
    for(int i = 0; i < adj[V].size(); i++){
        if(!visited[adj[V][i]]){
            dfs(adj[V][i], adj);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]){
    visited.clear();
    ans.clear();
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, adj);
        }
    }
    return ans;
}     