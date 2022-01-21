#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
struct stepsByKnight
{
    int x, y;
    stepsByKnight(int a, int b)
    {
        x = a;
        y = b;
    }
};
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {-1, 2, 2, 1, 1, -2, -2, -1};

bool isValid(int x, int y, int n){
    return x > 0 && x <= n && y > 0 && y <= n;
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
    queue<stepsByKnight> q;
    unordered_map<int, int> visited;
    q.push(stepsByKnight(KnightPos[0], KnightPos[1]));
    visited[KnightPos[0] * N + KnightPos[1]] = 1;
    while(!q.empty()){
        stepsByKnight cur = q.front();
        q.pop();
        int x = cur.x;
        int y = cur.y;
        if(x == TargetPos[0] && y == TargetPos[1]){
            return visited[x * N + y]-1;
        }
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx, ny, N) && (visited[nx * N + ny] == 0 || visited.find(nx*N+ny) == visited.end())){
                visited[nx * N + ny] = visited[x * N + y] + 1;
                q.push(stepsByKnight(nx, ny));
            }
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int>KnightPos(2);
    vector<int>TargetPos(2);
    for(int i = 0; i < 2; i++){
        cin >> KnightPos[i];
    }
    for(int i = 0; i < 2; i++){
        cin >> TargetPos[i];
    }
    cout << minStepToReachTarget(KnightPos, TargetPos, n);
    return 0;
}

