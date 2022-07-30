#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

struct subset
{
    int parent;
    int rank;
};

int find(vector<subset> subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<subset> &subsets, int xRoot, int yRoot)
{
    if (subsets[xRoot].rank < subsets[yRoot].rank)
    {
        subsets[xRoot].parent = yRoot;
    }
    else if (subsets[yRoot].rank < subsets[xRoot].rank)
    {
        subsets[yRoot].parent = xRoot;
    }
    else
    {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

int isCycle(int V, vector<vector<int>> adj)
{
    int v = adj.size();
    vector<subset> subsets(V);
    for (int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    for (int i = 0; i < adj.size(); i++)
    {
        int x = find(subsets, adj[i][0]);
        int y = find(subsets, adj[i][1]);
        if (x == y)
            return 1;
        Union(subsets, x, y);
    }
    return 0;
}

int compareVector(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    sort(adj->begin(), adj->end(), compareVector);
    vector<vector<int>> spanningTree;
    
    for (int i = 0; i < adj->size();i++){
        
    }
}