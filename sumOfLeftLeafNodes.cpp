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
    return node == NULL?false:node->left == NULL && node->right == NULL;
}

int leftLeavesSum(Node* root){
    int res = 0;
    if (root == NULL)
        return 0;
    if(isLeafNode(root->left))
        res += root->left->data;
    else
        res += leftLeavesSum(root->left);
    res += leftLeavesSum(root->right);
    return res;
}