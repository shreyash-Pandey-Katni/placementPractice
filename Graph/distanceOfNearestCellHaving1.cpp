#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;
struct ele
{
    int val;
    int x;
    int y;
    ele(int a, int b, int c)
    {
        val = a;
        x = b;
        y = c;
    }
};

bool isValid(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<ele> q;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                q.push(ele(0, i, j));
            }
        }
    }
    while (!q.empty())
    {
        ele cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        int val = cur.val;
        // ans[x][y] = val;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, n, m) && ans[x][y] == 0)
            {
                if (grid[nx][ny] == 1)
                {
                    ans[x][y] = 1;
                }
            }
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(ans[i][j] !=0 || grid[i][j] == 1)
            {
                continue;
            }
            int minTemp = INT_MAX;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (isValid(nx, ny, n, m) && ans[nx][ny] < minTemp && ans[nx][ny] != 0)
                {
                    minTemp = ans[nx][ny];
                }
            }
            ans[i][j] = minTemp + 1;
        }
    }
    
    return ans;
}
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
