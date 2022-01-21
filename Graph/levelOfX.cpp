#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
int levelOfX(int V, vector<int>adj[], int x)
{
    queue<int> q;
    q.push(0);
    int ans = 0;
    int size = 1;
    int tempSize = 0;
    while (!q.empty())
    {
        for (int i = 0; i < size; i++)
        {
            int cur = q.front();
            q.pop();
            if (cur == x)
                return ans;
            for (int j = 0; j < adj[cur].size(); j++)
            {
                tempSize++;
                q.push(adj[cur][j]);
            }
        }
        size = tempSize;
        tempSize = 0;
        ans++;
    }
    return -1;
}