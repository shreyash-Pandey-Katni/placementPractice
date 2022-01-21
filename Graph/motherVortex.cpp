#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
stack<int> st;
vector<bool> visited;

void dfs(int V, vector<int>adj[]){
    if(visited[V]) return;
    visited[V] = true;
    for(int i=0;i<adj[V].size();i++){
        dfs(adj[V][i],adj);
    }
    st.push(V);
}

void dfsUtil(int V, vector<int>adj[]){
    if(visited[V]) return;
    visited[V] = true;
    for(int i=0;i<adj[V].size();i++){
        if(!visited[adj[V][i]]){
            dfsUtil(adj[V][i],adj);
        }
    }
}

int findMotherVertex(int V, vector<int>adj[]){
    visited.assign(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj);
        }
    }
    int motherVertex = st.top();
    st.pop();
    visited.assign(V,false);
    dfsUtil(motherVertex,adj);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            return -1;
        }
    }
    return motherVertex;
}