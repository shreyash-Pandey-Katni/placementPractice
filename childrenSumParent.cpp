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
int isSumProperty(Node *node){
    if(node ==NULL)
        return 1;
    if(node->left == NULL && node->right == NULL)
        return 1;
    if(node->left == NULL)
        return (node->data == node->right->data) && isSumProperty(node->right);
    if(node->right == NULL)
        return (node->data == node->left->data) && isSumProperty(node->left);
    return (node->data == node->left->data + node->right->data) && isSumProperty(node->left) && isSumProperty(node->right);
}