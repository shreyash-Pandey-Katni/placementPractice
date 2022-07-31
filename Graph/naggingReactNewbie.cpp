#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

// implement bfs to find all paths from source to destination
// and return the those paths
vector<vector<int>> bfs(int source, int destination, vector<vector<int>> adj)
{
    vector<vector<int>> paths;
    vector<int> path;
    path.push_back(source);
    queue<vector<int>> q;
    q.push(path);
    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int last = path.back();
        if (last == destination)
        {
            paths.push_back(path);
        }
        for (int i = 0; i < adj[last].size(); i++)
        {
            vector<int> newPath = path;
            newPath.push_back(adj[last][i]);
            q.push(newPath);
        }
    }
    return paths;
}

// implement dfs to find all paths from source to destination
// and return the those paths
vector<vector<int>> dfs(int source, int destination, vector<vector<int>> adj)
{
    vector<vector<int>> paths;
    vector<int> path;
    path.push_back(source);
    stack<vector<int>> s;
    s.push(path);
    while (!s.empty())
    {
        path = s.top();
        s.pop();
        int last = path.back();
        if (last == destination)
        {
            paths.push_back(path);
        }
        for (int i = 0; i < adj[last].size(); i++)
        {
            vector<int> newPath = path;
            newPath.push_back(adj[last][i]);
            s.push(newPath);
        }
    }
    return paths;
}

// implement max flow min cut using bfs
// and return the max flow and min cut
pair<int, vector<int>> maxFlowMinCut(int source, int destination, vector<vector<int>> adj)
{
    vector<int> parent(adj.size(), -1);
    vector<int> visited(adj.size(), 0);
    vector<int> path;
    path.push_back(source);
    queue<vector<int>> q;
    q.push(path);
    int maxFlow = 0;
    while (!q.empty())
    {
        path = q.front();
        q.pop();
        int last = path.back();
        if (last == destination)
        {
            maxFlow++;
            vector<int> minCut;
            for (int i = 0; i < path.size(); i++)
            {
                if (parent[path[i]] != -1)
                {
                    minCut.push_back(path[i]);
                }
            }
            return make_pair(maxFlow, minCut);
        }
        for (int i = 0; i < adj[last].size(); i++)
        {
            vector<int> newPath = path;
            newPath.push_back(adj[last][i]);
            if (!visited[adj[last][i]])
            {
                parent[adj[last][i]] = last;
                visited[adj[last][i]] = 1;
                q.push(newPath);
            }
        }
    }
    return make_pair(maxFlow, vector<int>());
}

int findMinEdges(vector<pair<int, int>> arr, int N)
{
    int minEdges = 0;
    int reachable = 0;
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < arr.size(); i++)
    {
        if (reachable > arr[i].first)
        {
            continue;
        }
        else
        {
            reachable = arr[i].second;
            minEdges++;
        }
    }
    return minEdges;
}
// write a function to determine minimum set of edges to be removed so that there is no path between two give nodes

int main(){
    int n, e;
    cin >> n;
    unordered_map<int, int> mp;
    unordered_map<int, int> rev;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x] = i;
        rev[i] = x;
    }
    cin >> e;
    vector<vector<int>> adj;
    adj.resize(n);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[mp[x]].push_back(mp[y]);
    }
    int src, dest;
    cin >> src >> dest;
    pair<int, vector<int>> ans = maxFlowMinCut(mp[src], mp[dest], adj);
    cout << ans.first << endl;
    for (int i = 0; i < ans.second.size(); i++)
    {
        cout << rev[ans.second[i]] << " ";
    }
    cout << endl;
    return 0;
}