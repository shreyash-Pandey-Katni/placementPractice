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
int minDepth(Node *root){
    if(root == NULL)
        return 0;
    if(isLeaf(root))
        return 1;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if(left == 0 || right == 0)
        return left + right + 1;
    return min(left, right) + 1;
}