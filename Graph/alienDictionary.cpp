#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int positionOfDifference(string s1, string s2)
{
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            return i;
        }
    }
    return -1;
}

void dfs(int V, vector<bool> &visited, vector<int> adj[], vector<int> &res)
{
    visited[V] = true;
    for (int i = 0; i < adj[V].size(); i++)
    {
        if (!visited[adj[V][i]])
        {
            dfs(adj[V][i], visited, adj, res);
        }
    }
    res.push_back(V);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> res;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, res);
        }
    }
    return res;
}

string findOrder(string dict[], int N, int K)
{
    int V = K;
    vector<int> adj[V];
    for (int i = 0; i < N - 1; i++)
    {
        int pos = positionOfDifference(dict[i], dict[i + 1]);
        if (pos != -1)
        {
            adj[dict[i][pos] - 'a'].push_back(dict[i + 1][pos] - 'a');
        }
    }
    vector<int> res = topoSort(V, adj);
    string ans = "";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        ans += (char)(res[i] + 'a');
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    string dict[n];
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    cout << findOrder(dict, n, k);
    return 0;
}
