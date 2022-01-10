#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
vector<vector<int>> result;

void levelOrderUtil(Node *root, int level){
    if(root == NULL)
        return;
    if(result.size() <= level)
        result.push_back(vector<int>());
    result[level].push_back(root->data);
    levelOrderUtil(root->left, level + 1);
    levelOrderUtil(root->right, level + 1);
}

vector<vector<int>> levelOrder(Node *node){
    result.clear();
    if(node == NULL)
        return result;
    levelOrderUtil(node, 0);
    return result;
}