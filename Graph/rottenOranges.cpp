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

bool isValid(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isSurroundingZero(vector<vector<int>> &grid, int x, int y, int n, int m){
    int count = 0;
    int numValid = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx, ny, n, m)){
            if(grid[nx][ny] == 0)
                count++;
            numValid++;
        }
    }
    return count == numValid;
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
            } else if (grid[i][j] == 1 && isSurroundingZero(grid, i, j, n, m)){
                return -1;
            }
        }
    }
    q.push(element(-1, -1, -1));
    int count = 0;
    while(!q.empty()){
        element curr = q.front();
        q.pop();
        if(isDelimiter(curr.val)){
            if(!q.empty()){
                q.push(element(-1, -1, -1));
            }
            count++;
            continue;
        }
        int x = curr.indexX;
        int y = curr.indexY;
        if(isValid(x - 1, y, n, m) && grid[x - 1][y] == 1){
            grid[x - 1][y] = 2;
            q.push(element(grid[x - 1][y], x - 1, y));
        }
        if(isValid(x + 1, y, n, m) && grid[x + 1][y] == 1){
            grid[x + 1][y] = 2;
            q.push(element(grid[x + 1][y], x + 1, y));
        }
        if(isValid(x, y - 1, n, m) && grid[x][y - 1] == 1){
            grid[x][y - 1] = 2;
            q.push(element(grid[x][y - 1], x, y - 1));
        }
        if(isValid(x, y + 1, n, m) && grid[x][y + 1] == 1){
            grid[x][y + 1] = 2;
            q.push(element(grid[x][y + 1], x, y + 1));
        }
    }
    return count-1;
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> grid;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            int data;
            cin >> data;
            temp.push_back(data);
        }
        grid.push_back(temp);
    }
    cout << orangesRotting(grid) << endl;
    return 0;
}
