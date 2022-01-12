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

vector<Node*> inorderNodes;
vector<int> temp;
void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    inorderNodes.push_back(root);
    temp.push_back(root->data);
    inorder(root->right);
}

Node* binaryTreeToBST(Node* root){
    inorderNodes.clear();
    temp.clear();
    inorder(root);
    sort(temp.begin(), temp.end());
    for(int i = 0; i < inorderNodes.size(); i++){
        inorderNodes[i]->data = temp[i];
    }
    return root;
}