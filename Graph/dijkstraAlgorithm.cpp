#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
#include<queue>
using namespace std;

vector<int> dijkstraAlgorithm(int V, vector<vector<int>> adj[], int s){
    vector<int> res(V, INT_MAX);
    res[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        pair<int, int> curr = pq.top();
        pq.pop();
        int u = curr.second;
        for (int i = 0; i < adj[u].size();i++){
            int v = adj[u][i][1];
            int w = adj[u][i][0];
            if(res[u]+w < res[v]){
                res[v] = res[u] + w;
                pq.push({res[v], v});
            }
        }
    }
    return res;
}