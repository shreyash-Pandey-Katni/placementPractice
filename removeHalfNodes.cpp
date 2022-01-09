#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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
Node* RemoveHalfNodes(Node* root){
    if(root == NULL)
        return NULL;
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    if(root->left == NULL && root->right == NULL)
        return root;
    if(root->left == NULL)
        return root->right;
    if(root->right == NULL)
        return root->left;
    return root;
}