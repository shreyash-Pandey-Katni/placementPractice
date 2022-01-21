#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
bool isValid(int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}
bool isWall(int data)
{
    return data == 0;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool is_possible(vector<vector<int>>&grid){
    queue<vector<int>> q;
    int n = grid.size();
    int srcX ,srcY;
    int destX, destY;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
                srcX = i;
                srcY = j;
            }
            if(grid[i][j] == 2){
                destX = i;
                destY = j;
            }
        }
    }
    q.push({srcX,srcY});
    grid[srcX][srcY] = 0;
    while(!q.empty()){
        vector<int> curr = q.front();
        q.pop();
        if(curr[0] == destX && curr[1] == destY){
            return true;
        }
        for(int i=0;i<4;i++){
            int x = curr[0] + dx[i];
            int y = curr[1] + dy[i];
            if(x == destX && y == destY){
                return true;
            }
            if(isValid(x,y,n) && isWall(grid[x][y])){
                grid[x][y] = 0;
                q.push({x,y});
            }
        }
    }

    return false; 
}