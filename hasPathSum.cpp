#include<iostream>
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
bool hasPathSum(Node* root, int sum){
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL && root->data == sum)
        return true;
    return hasPathSum(root->left, sum - root->data) || hasPathSum(root->right, sum - root->data);
}