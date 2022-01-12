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

bool isLeaf(Node *root)
{
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

int toSumTreeUtil(Node *node){
    if(node == NULL)
        return 0;
    if(isLeaf(node)){
        int temp = node->data;
        node->data = 0;
        return temp;
    }
    int ls = toSumTreeUtil(node->left);
    int rs = toSumTreeUtil(node->right);
    int oldVal = node->data;
    node->data = ls + rs;
    return node->data + oldVal;
}

void toSumTree(Node *node){
    if(node == NULL){
        return;
    }
    toSumTreeUtil(node);
}