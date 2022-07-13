#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <bits/stdc++.h>
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
    vector<vector<int>> ans = grid;
    int n = grid.size();
    int m = grid[0].size();
    int visited[n][m] = {0};
    queue<ele> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                ans[i][j] = 0;
                visited[i][j] = 1;
                q.push(ele(0, i, j));
            }
        }
    }
    int currDist = 1;
    q.push(ele(-1, 0, 0));
    while (!q.empty())
    {
        ele curr = q.front();
        q.pop();
        if (curr.val == -1)
        {
            currDist++;
            if (!q.empty())
                q.push(ele(-1, 0, 0));
            continue;
        }
        int x = curr.x;
        int y = curr.y;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny, n, m) && grid[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                ans[nx][ny] = currDist;
                visited[nx][ny] = 1;
                q.push(ele(currDist, nx, ny));
            }
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
    cout << "Answer is:" << endl;
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
