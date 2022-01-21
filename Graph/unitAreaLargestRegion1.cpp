#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

struct unitAreaLargestRegion1
{
    int x,y;
    unitAreaLargestRegion1(int _x,int _y):x(_x),y(_y){}
};

bool isValid(int x,int y,int n,int m)
{
    return x>=0 && x<n && y>=0 && y<m;
}

int count = 0;
void dfs(vector<vector<int>> &grid, int x, int y, int n, int m, vector<vector<bool>> &visited, int &count)
{
    visited[x][y] = true;
    for(int i=0;i<8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx,ny,n,m) && !visited[nx][ny] && grid[nx][ny] == 1){
            count++;
            dfs(grid,nx,ny,n,m,visited,count);
        }
    }
}

int findMaxArea(vector<vector<int>>&grid){
    int n = grid.size();
    if(n == 0) return 0;
    int m = grid[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    int maxArea = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                if (!visited[i][j])
                {
                    count = 1;
                    dfs(grid, i, j, n, m, visited, count);
                    maxArea = max(maxArea, count);
                }
            }
        }
        
    }
    return maxArea;
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << findMaxArea(grid);
    return 0;
}
