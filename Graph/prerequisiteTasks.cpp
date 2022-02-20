#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// int find(vector<int> parent, int i)
// {
//     if (parent[i] == -1)
//         return i;
//     return find(parent, parent[i]);
// }

// void Union(vector<int> parent, int x, int y){
//     parent[x] = y;
// }

// bool hasCycle(int V, vector<vector<int>>adj){
//     vector<int> parent(V, -1);
//     for(int i=0;i<adj.size();i++){
//         int x = find(parent, adj[i][0]);
//         int y = find(parent, adj[i][1]);
//         if(x==y)
//             return true;
//         Union(parent, x, y);
//     }
//     return false;
// }

bool isCyclicUtil(int V, vector<bool> visited, vector<bool>&recStack, vector<vector<int>>adj){
    if(visited[V] == false){
        visited[V] = true;
        recStack[V] = true;
        for(int i=0;i<adj[V].size();i++){
            if(!visited[adj[V][i]] && isCyclicUtil(adj[V][i], visited, recStack, adj))
                return true;
            else if(recStack[adj[V][i]])
                return true;
        }
    }
    recStack[V]=false;
    return false;
}

bool isCyclic(int V, vector<vector<int>>adj){
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);
    for(int i=0;i<V;i++){
        if(isCyclicUtil(i, visited, recStack, adj))
            return true;
    }
    return false;
}

bool isPossible(int N, vector<pair<int, int>>&prerequisiteTasks)
{
    vector<vector<int>> adj(N);
    for(int i=0;i<prerequisiteTasks.size();i++){
        adj[prerequisiteTasks[i].second].push_back(prerequisiteTasks[i].first);
    }
    return !isCyclic(N, adj);
}
int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> prerequisiteTasks(M);
    for (int i = 0; i < M; i++)
    {
        cin >> prerequisiteTasks[i].first >> prerequisiteTasks[i].second;
    }
    cout << isPossible(N, prerequisiteTasks) << endl;
    return 0;
}
