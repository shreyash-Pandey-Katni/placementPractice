#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dfsDepth(vector<vector<int>> &adj, int u, int parent, int depth)
{
    int maxDepth = depth;
    for (int v : adj[u])
    {
        if (v == parent)
            continue;
        int d = dfsDepth(adj, v, u, depth + 1);
        if (d > maxDepth)
            maxDepth = d;
    }
    return maxDepth;
}

vector<int> depthOfUndirectedGraphWithRemovalOfEdge(int N, int Q, vector<vector<int>> &Edge, vector<vector<int>> &query)
{
    vector<int> ans;
    vector<vector<int>> adj(N);
    for (int i = 0; i < Edge.size(); i++)
    {
        adj[Edge[i][0]].push_back(Edge[i][1]);
        adj[Edge[i][1]].push_back(Edge[i][0]);
    }
    vector<vector<int>> tempAdj(N);
    tempAdj = adj;
    int maxDepth = dfsDepth(adj, 0, -1, 0);
    for (int i = 0; i < query.size(); i++)
    {
        int temp = query[i][0];
        int temp2 = query[i][1];
        tempAdj = adj;
        if (temp == temp2)
        {
            ans.push_back(maxDepth);
        }
        else
        {
            tempAdj[temp].erase(find(tempAdj[temp].begin(), tempAdj[temp].end(), temp2));
            tempAdj[temp2].erase(find(tempAdj[temp2].begin(), tempAdj[temp2].end(), temp));
            maxDepth = dfsDepth(adj, 0, -1, 0);
            ans.push_back(maxDepth);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int N, Q;
    cin >> N;
    cin >> Q;
    vector<vector<int>> Edge(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        int temp;
        cin >> temp;
        Edge[i].push_back(temp);
        cin >> temp;
        Edge[i].push_back(temp);
    }
    vector<vector<int>> query(Q);
    for (int i = 0; i < Q; i++)
    {
        int temp;
        cin >> temp;
        query[i].push_back(temp);
        cin >> temp;
        query[i].push_back(temp);
    }
    vector<int> ans = depthOfUndirectedGraphWithRemovalOfEdge(N, Q, Edge, query);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
