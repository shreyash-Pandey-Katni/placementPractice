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
bool isLeaf(Node *root){
    if(root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}
// int leafLevel = INT_MAX;
vector<int> leafLevel;
void checkUtil(Node *root, int level)
{
    if(root == NULL)
    return;
        // return false;
    if(isLeaf(root))
    {
        // leafLevel = min(leafLevel, level);
        leafLevel.push_back(level);
        // return true;
    }
    checkUtil(root->left, level + 1);
    checkUtil(root->right, level + 1);
    // return checkUtil(root->left, level + 1) && checkUtil(root->right, level + 1);
}

bool check(Node *root)
{
    if(root == NULL)
    return true;
    leafLevel.clear();
    checkUtil(root, 0);
    int prev = leafLevel[0];
    for(int i = 1; i < leafLevel.size(); i++)
    {
        if(leafLevel[i] - prev != 0)
        return false;
        prev = leafLevel[i];
    }
    return true;
}