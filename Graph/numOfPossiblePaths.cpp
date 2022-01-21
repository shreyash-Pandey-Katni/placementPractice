#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;

int ans = 0;

void dfs(int v, vector<int>adj[], int dest){
    if(v == dest){
        ans++;
        return;
    }
    for(int i = 0; i < adj[v].size(); i++){
        dfs(adj[v][i], adj, dest);
    }
}

int countPaths(int V, vector<int> adj[], int source, int destination){
    ans = 0;
    dfs(source, adj, destination);
    return ans;
}
int main(int argc, char const *argv[])
{
    int V, E;
    cin >> V >> E;
    vector<int>adj[V];
    for (int i = 0;i<E;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int src, dest;
    cin >> src >> dest;
    cout << countPaths(V, adj, src, dest) << endl;
    return 0;
}
