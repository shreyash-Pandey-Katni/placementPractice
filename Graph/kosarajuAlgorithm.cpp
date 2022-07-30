#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
#include<stack>
using namespace std;

void fillOrder(int V,vector<bool> visited, stack<int> &s, vector<int> adj[]){
    visited[V] = true;
    // list<int>::iterator i;
    for(int i = 0; i < adj[V].size(); i++){
        if(!visited[adj[V][i]]){
            fillOrder(adj[V][i], visited, s, adj);
        }
    }
    s.push(V);
}

void transposeGraph(vector<int> adj[], int V, vector<int> adjT[]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < adj[i].size(); j++){
            adjT[adj[i][j]].push_back(i);
        }
    }
}

void DFS(vector<int> adj[], int V, vector<bool> &visited, int u){
    visited[u] = true;
    for(int i = 0; i < adj[u].size(); i++){
        if(!visited[adj[u][i]]){
            DFS(adj, V, visited, adj[u][i]);
        }
    }
}

stack<int> st;

void dfs(int V, vector<bool> &visited, vector<int> adj[])
{
    visited[V] = true;
    for (int i = 0; i < adj[V].size(); i++)
    {
        if (!visited[adj[V][i]])
        {
            dfs(adj[V][i], visited, adj);
        }
    }
    st.push(V);
}

vector<int> topoSort(int V, vector<int> adj[])
{

    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int kosaraju(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    stack<int> s;
    fillOrder(0, visited, s, adj);
    vector<int> adjT[V];
    transposeGraph(adj, V, adjT);
    visited.assign(V, false);
    int cnt = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        if(!visited[u]){
            DFS(adjT, V, visited, u);
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << kosaraju(V, adj) << endl;
    return 0;
}
