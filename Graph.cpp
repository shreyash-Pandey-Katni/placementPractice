#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
public:
    vector<vector<int>> adj;
    unordered_map<int, int> inDegree;
    unordered_map<int, int> outDegree;
    Graph(int n)
    {
        adj.resize(n);
        inDegree.reserve(n);
        outDegree.reserve(n);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
        inDegree[v]++;
        outDegree[u]++;
    }
    void removeEdge(int u, int v)
    {
        adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        inDegree[v]--;
        outDegree[u]--;
    }
    void DFSUtil(int u, vector<bool> &visited)
    {
        visited[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
                DFSUtil(v, visited);
        }
    }
    void DFS(int u)
    {
        vector<bool> visited(adj.size(), false);
        DFSUtil(u, visited);
    }
    void BFS(int u)
    {
        vector<bool> visited(adj.size(), false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    void removeVertex(int u)
    {
        for (int v : adj[u])
        {
            inDegree[v]--;
            outDegree[v]--;
        }
        adj.erase(adj.begin() + u);
        for (int i = 0; i < adj.size(); i++)
        {
            vector<int> &v = adj[i];
            v.erase(remove(v.begin(), v.end(), u), v.end());
        }
    }
    void addVertex(int u)
    {
        adj.insert(adj.begin() + u, vector<int>());
        inDegree[u] = 0;
        outDegree[u] = 0;
    }
    bool isMountain(int u)
    {
        return inDegree[u] == 0 && outDegree[u] == 0;
    }
    bool isValley(int u)
    {
        return inDegree[u] == 0 && outDegree[u] > 0;
    }
    bool isPeak(int u)
    {
        return inDegree[u] > 0 && outDegree[u] == 0;
    }
    bool isEdge(int u, int v)
    {
        return find(adj[u].begin(), adj[u].end(), v) != adj[u].end();
        // return find(adjList[u].begin(), adjList[u].end(), v) != adjList[u].end();
    }
    bool isConnected(int u, int v)
    {
        return isEdge(u, v) || isEdge(v, u);
    }
    bool isConnected(int u)
    {
        return inDegree[u] == 0;
    }
    int getInDegree(int u)
    {
        return inDegree[u];
    }
    int getOutDegree(int u)
    {
        return outDegree[u];
    }
    vector<int> getAdjList(int u)
    {
        return adj[u];
        // return adjList[u];
    }
    void printGraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            cout << i << ": ";
            for (int j : adj[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.printGraph();
    return 0;
}
