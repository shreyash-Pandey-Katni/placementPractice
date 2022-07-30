#include <iostream>
#include <vector>
#include <unordered_set>
#include<queue>
#include <bits/stdc++.h>
using namespace std;
int isBridge(int V, vector<int> adj[], int c, int d)
{
    for(int i = 0; i < adj[c].size(); i++)
    {
        if(adj[c][i] == d)
        {
            adj[c].erase(adj[c].begin() + i);
        }
    }
    for(int i = 0; i < adj[d].size(); i++)
    {
        if(adj[d][i] == c)
        {
            adj[d].erase(adj[d].begin() + i);
        }
    }
    queue<int> q;
    q.push(c);
    vector<bool> visited(V, false);
    visited[c] = true;
    while(!q.empty())
    {
        int u = q.front();
        if(u == d)
        {
            return 1;
        }
        q.pop();
        for(int i = 0; i < adj[u].size(); i++)
        {
            if(!visited[adj[u][i]])
            {
                visited[adj[u][i]] = true;
                q.push(adj[u][i]);
            }
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c, d;
    cin >> c >> d;
    if(isBridge(V, adj, c, d))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
