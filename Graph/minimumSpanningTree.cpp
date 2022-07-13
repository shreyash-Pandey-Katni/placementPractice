#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct subset
{
    int parent;
    int rank;
};

struct linkedList
{
    int data;
    int src;
    int dest;
    linkedList *next;
};

linkedList *newNode(int data, int src, int dest)
{
    linkedList *temp = new linkedList;
    temp->data = data;
    temp->src = src;
    temp->dest = dest;
    temp->next = NULL;
    return temp;
}

//ToDo: Add a function to check if the graph is cyclic or not

linkedList* insert(linkedList *head, int data, int src, int dest)
{
    linkedList *temp = newNode(data, src, dest);
    
}

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

static bool compareVect(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

// int find(int parent[], int i)
// {
//     if (parent[i] == -1)
//         return i;
//     return find(parent, parent[i]);
// }

// void Union(int parent[], int x, int y)
// {
//     parent[x] = y;
// }

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
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> visited(V, false);
    vector<vector<int>> temp;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            temp.push_back({i, adj[i][j][0], adj[i][j][1]});
        }
    }
    sort(temp.begin(), temp.end(), compareVect);
    vector<vector<int>> temp2;
    int weight = 0;
    int finalWeight = INT_MAX;
    int count = 0;
    for (int i = 0; i < temp.size() && count < V; i += 2)
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
