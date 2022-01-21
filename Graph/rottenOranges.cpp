#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct element{
    int val;
    int indexX;
    int indexY;
    element(int v, int x, int y) : val(v), indexX(x), indexY(y){};
};

bool isValid(int x, int y, int n, int m, int data){
    return x >= 0 && x < n && y >= 0 && y < m && data == 1;
}

bool isDelimiter(int data){
    return data == -1;
}

int orangesRotting(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<element> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push(element(grid[i][j], i, j));
            }
        }
    }
    int count = 0;
    while(!q.empty()){
        element curr = q.front();
        q.pop();
        int x = curr.indexX;
        int y = curr.indexY;
        if(isValid(x - 1, y, n, m, grid[x - 1][y]) && isDelimiter(grid[x - 1][y])){
            grid[x - 1][y] = 2;
            q.push(element(grid[x - 1][y], x - 1, y));
        }
        if(isValid(x + 1, y, n, m, grid[x + 1][y]) && isDelimiter(grid[x + 1][y])){
            grid[x + 1][y] = 2;
            q.push(element(grid[x + 1][y], x + 1, y));
        }
        if(isValid(x, y - 1, n, m, grid[x][y - 1]) && isDelimiter(grid[x][y - 1])){
            grid[x][y - 1] = 2;
            q.push(element(grid[x][y - 1], x, y - 1));
        }
        if(isValid(x, y + 1, n, m, grid[x][y + 1]) && isDelimiter(grid[x][y + 1])){
            grid[x][y + 1] = 2;
            q.push(element(grid[x][y + 1], x, y + 1));
        }
        count++;
    }
    return count;
}