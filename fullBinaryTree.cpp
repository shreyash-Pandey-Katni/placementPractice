#include<iostream>
#include<vector>
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

bool isFullTree(Node* root)
{
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    if(root->left != NULL && root->right != NULL)
        return isFullTree(root->left) && isFullTree(root->right);
    return false;
}