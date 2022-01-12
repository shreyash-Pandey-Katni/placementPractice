#include<iostream>
#include<vector>
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
bool isMirror(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}
bool isSymmetric(Node *root)
{
    if(root == NULL)
        return true;
    return isMirror(root->left, root->right);
}