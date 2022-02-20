#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool compareVect(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
    parent[x] = y;
}

// The main function to check whether a given graph contains
// cycle or not
int isCycle(int V, vector<vector<int>>adj)
{
    // Allocate memory for creating V subsets
    int *parent = new int[V * sizeof(int)];

    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * V);

    // Iterate through all edges of graph, find subset of
    // both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.
    for (int i = 0; i < adj.size(); ++i)
    {
        int x = find(parent, adj[i][0]);
        int y = find(parent, adj[i][1]);

        if (x == y)
            return 1;

        Union(parent, x, y);
    }
    return 0;
}
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> visited(V, false);
    vector<vector<int>> temp;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            temp.push_back({i, adj[i][j][0], adj[i][j][1]});
            sort(temp.begin(), temp.end(), compareVect);
        }
    }
    vector<vector<int>> temp2;
    int weight = 0;
    int finalWeight = INT_MAX;
    int count = 0;
    for (int i = 0; i < temp.size() && count < V ; i++)
    {
        temp2.push_back(temp[i]);
        weight += temp[i][2];
        if (isCycle(V, temp2))
        {
            temp2.pop_back();
            weight -= temp[i][2];
        }
        else
        {
            count++;
        }
    }

    finalWeight = weight;
    return finalWeight;
}
int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i = 0;
    while (i++ < E)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << spanningTree(V, adj) << endl;
    return 0;
}
