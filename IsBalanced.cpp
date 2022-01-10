#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int getHeight(Node *root){
    if(root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root){
    if(root == NULL)
        return true;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if(abs(leftHeight-rightHeight) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}