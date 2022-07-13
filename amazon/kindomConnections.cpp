#include<bits/stdc++.h>
using namespace std;

// There are N provinces in the kingdom. A pair of provinces are connected by land and B pair of provinces are connected by water.
// For each captured province connected to it by land should also be captured.
// No Two provinces are connected by water directly or by any other provinces.
// Any captured provinces should be connected directly or through other captured provinces.
// input:
// N = 5
// A = 2
// B = 1
// land = [[1,2],[2,3]]
// water = [[2,3]]

// output:
// 1

// depth first search to find maximum depth of the graph
int dfs(vector<vector<int>> &graph, int node, int depth, vector<bool> &visited)
{
    visited[node] = true;
    int maxDepth = depth;
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!visited[graph[node][i]])
        {
            int temp = dfs(graph, graph[node][i], depth + 1, visited);
            if (temp > maxDepth)
            {
                maxDepth = temp;
            }
        }
    }
    return maxDepth;
}

void dfs_with_depth_count(int u, vector<vector<int>> &graph, vector<int> &visited, int &depth, int &count, int &maxDepth)
{
    visited[u] = 1;
    depth++;
    maxDepth = max(maxDepth, depth);
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs_with_depth_count(v, graph, visited, depth, count, maxDepth);
        }
    }
    depth--;
    if (depth == 0)
    {
        count++;
    }
}

int solve(int N, int A, int B, vector<vector<int>> land, vector<vector<int>> water)
{
    int max_depth = 0;
    unordered_set<int> water_set;
    vector<bool> visited(N, 0);
    vector<vector<int>> graph(N);
    for (int i = 0; i < land.size(); i++)
    {
        graph[land[i][0] - 1].push_back(land[i][1] - 1);
        graph[land[i][1] - 1].push_back(land[i][0] - 1);
    }
    for (int i = 0; i< B; i++)
    {
        if(water_set.find(water[i][1] - 1) == water_set.end())
        {
                graph[water[i][1]].clear();
                water_set.insert(water[i][1] - 1);
            
        }
        if (water_set.find(water[i][0] - 1) == water_set.end())
        {
            graph[water[i][0]].clear();
            water_set.insert(water[i][0] - 1);
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
        {
            int depth = 1;
            int count = 0;
            max_depth = max(max_depth, dfs(graph, i, depth, visited));
        }
    }
    if (max_depth == 1)
    {
        return 0;
        
    }
    if (max_depth == 2)
    {
        return 1;
    }
    return max_depth;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int A;
        cin >> A;
        int B;
        cin >> B;
        vector<vector<int>> land(A, vector<int>(2));
        for (int i_land = 0; i_land < A; i_land++)
        {
            for (int j_land = 0; j_land < 2; j_land++)
            {
                cin >> land[i_land][j_land];
            }
        }
        vector<vector<int>> water(B, vector<int>(2));
        for (int i_water = 0; i_water < B; i_water++)
        {
            for (int j_water = 0; j_water < 2; j_water++)
            {
                cin >> water[i_water][j_water];
            }
        }

        int out_;
        out_ = solve(N, A, B, land, water);
        cout << out_;
        cout << "\n";
    }
}