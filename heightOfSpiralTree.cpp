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
bool isLeafNode(Node *node){
    return node->left && node->left->right == node && node->right && node->right->left == node;
}
int findTreeHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    if(isLeafNode(root))
        return 1;
    int leftHeight = findTreeHeight(root->left);
    int rightHeight = findTreeHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}