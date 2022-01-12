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
int maxDifference = INT_MIN;

bool isLeaf(Node* root){
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void maxDiffUtil(Node* root, int parent){
    if(root == NULL)
        return;
    int diff;
    if(parent != -1){
        diff = parent - root->data;
        maxDifference = max(maxDifference, diff);
    }
    parent =max(parent, root->data);
    // maxDifference = max(maxDifference, diff);
    maxDiffUtil(root->left, parent);
    maxDiffUtil(root->right, parent);
}
int maxDiff(Node *root)
{
    maxDifference = INT_MIN;
    maxDiffUtil(root,-1);
    return maxDifference;
}