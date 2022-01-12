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

vector<int> temp;
void inorder(Node *root, int K){
    if(root == NULL || temp.size() == K)
        return;
    inorder(root->left, K);
    temp.push_back(root->data);
    inorder(root->right, K);
}

int kthLargest(Node* root, int K){
    temp.clear();
    inorder(root, K);
    return temp[K-1];
}