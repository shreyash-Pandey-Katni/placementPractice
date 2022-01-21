#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
#define N 100005
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct graph {
    struct ListNode *head[N];
};
struct edges {
    int src, dest;
};
vector<bool> visitedBool;
bool isCyclicUtil(int V, vector<int> adj[], bool *visited, int parent)
{
    if(!visited[V]){
        visited[V] = true;
        visitedBool[V] = true;
        for (vector<int>::iterator i = adj[V].begin(); i != adj[V].end(); ++i){
            if (!visited[*i] && isCyclicUtil(*i, adj, visited, V))
                return true;
            else if( *i != parent && visitedBool[*i])
                return true;
        }
    }
    visitedBool[V] = false;
    return false;
}

bool isCycle(int V, vector<int>adj[]){
    bool visited[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
        visitedBool.push_back(false);
    }
    for (int i = 0; i < V; i++)
    {
        if(isCyclicUtil(i,adj, visited,-1)){
            return true;
        }
    }
    return false;
}