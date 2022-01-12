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
vector<vector<int>> ans;
bool isLeaf(Node *root){
    if(root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}
void PathsUtil(Node* root, vector<int> path){
    if(root == NULL)
        return;
    path.push_back(root->data);
    if(isLeaf(root)){
        ans.push_back(path);
        return;
    }
    PathsUtil(root->left, path);
    PathsUtil(root->right, path);
    path.pop_back();
}
vector<vector<int>> Paths(Node* root){
    ans.clear();
    vector<int> path;
    PathsUtil(root, path);
    return ans;
}