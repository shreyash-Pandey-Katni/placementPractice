#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
unordered_map<int, bool> visited;

// void bfs(int V, vector<int> adj[]){
//     queue<int> q;
//     q.push(V);
//     visited[V] = true;
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         ans.push_back(u);
//     }

vector<int> bfsOfGraphUtil(int V, vector<int> adj[])
{
    queue<int> q;
    visited[V] = true;
    q.push(V);
    vector<int>::iterator i;
    while (!q.empty())
    {
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for (i = adj[temp].begin(); i != adj[temp].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    return ans;
}

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    visited.clear();
    ans.clear();
    bfsOfGraphUtil(0, adj);
    return ans;
}

int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> res = bfsOfGraph(V, adj);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
