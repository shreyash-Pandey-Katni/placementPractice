#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// vector<vector<int>> levelOrderVector;
vector<int> ans;
void levelOrder(Node *root)
{
    if(root == NULL)
        return;
    queue<Node*> q;
    int level = 0;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> v;
        for(int i=0; i<size; i++){
            Node* temp = q.front();
            q.pop();
            v.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            
        }
        if(level%2 == 0)
            ans.push_back(v[v.size()-1]);
        else
            ans.push_back(v[0]);
        v.clear();
        // levelOrderVector.push_back(v);
        level++;
    }
}
vector<int> ExtremeNodes(Node *root){
    vector<int> v;
    if(root == NULL)
        return v;
    levelOrder(root);
    return ans;
    // return v;
}