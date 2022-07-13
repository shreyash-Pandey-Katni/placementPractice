#include <iostream>
#include <list>
using namespace std;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph
{
    int V; // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // A function used by DFS
    void DFSUtil(int v, bool visited[]);
    void BFSUtil(int v, bool visited[]);

public:
    Graph(int V); // Constructor
    ~Graph();
    void addEdge(int v, int w);
    int connectedComponents();
    int bfsConnectedComponents();
};

// Method to print connected components in an
// undirected graph
int Graph::connectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int count = 0; // Initialize count as 0
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            // print all reachable vertices
            // from v
            count++;
            DFSUtil(v, visited);
            cout << "\n";
        }
    }
    delete[] visited;
    return count;
}

int Graph::bfsConnectedComponents()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    int count = 0; // Initialize count as 0
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            // print all reachable vertices
            // from v
            count++;
            BFSUtil(v, visited);
            cout << "\n";
        }
    }
    delete[] visited;
    return count;
}


void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::BFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v + 1 << " ";

    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            BFSUtil(*i, visited);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    int numberOfNodes;
    int numberOfEdges;
    cin >> numberOfNodes >> numberOfEdges;
    Graph g(numberOfNodes);
    for (int i = 0; i < numberOfEdges; i++)
    {
        int v, w;
        cin >> v >> w;
        g.addEdge(v - 1, w - 1);
    }
    cout << g.connectedComponents();
    return 0;
}