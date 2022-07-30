#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>

#ifndef COL
#define COL 501

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
vector<vector<int>> countIslands(int M[][COL], int n, int m){
    int count = 0;
    vector<vector<int>> ans = vector<vector<int>>(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<ele> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
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
            if (isValid(nx, ny, n, m) && M[nx][ny] == 0 && visited[nx][ny] == 0)
            {
                ans[nx][ny] = currDist;
                visited[nx][ny] = 1;
                q.push(ele(currDist, nx, ny));
            }
        }
    }
    return ans;
}

#endif