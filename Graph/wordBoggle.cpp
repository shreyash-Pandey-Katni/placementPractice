#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
using namespace std;
bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
bool isFound = false;
void dfs(vector<vector<char>> &grid, string target, int matchPos, int x, int y, vector<vector<bool>> &visited, string temp)
{
    int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
    if (matchPos == target.size() || isFound)
    {
        if (temp == target)
        {
            isFound = true;
        }
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, grid.size(), grid[0].size()) && !visited[nx][ny] && grid[nx][ny] == target[matchPos])
        {
            dfs(grid, target, matchPos + 1, nx, ny, visited, temp + grid[nx][ny]);
        }
    }
    visited[x][y] = false;
}
bool isWordExist(vector<vector<char>> &grid, string target)
{
    isFound = false;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == target[0])
            {
                string temp(1, grid[i][j]);
                dfs(grid, target, 1, i, j, visited, temp);
            }
            if (isFound)
            {
                return true;
            }
        }
    }
    return false;
}
vector<string> wordBoggle(vector<vector<char>>& grid, vector<string>& words)
{
    vector<string> res;
    for (int i = 0; i < words.size(); i++)
    {
        if (isWordExist(grid, words[i]))
        {
            res.push_back(words[i]);
        }
    }
    return res;
}