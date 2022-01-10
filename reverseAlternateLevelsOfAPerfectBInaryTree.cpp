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

void preorder(Node *root1, Node *root2, int level){
    if(root1 == NULL || root2 == NULL)
        return;
    if(level%2 == 0)
        swap(root1->data, root2->data);
    preorder(root1->left, root2->right, level + 1);
    preorder(root1->right, root2->left, level + 1);
}

void reverseAlternate(Node *root){
    if(root == NULL)
        return;
    preorder(root->left, root->right, 1);
}