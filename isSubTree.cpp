#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
bool isSameTree(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    return root1->data==root2->data && isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}

Node* findTarget(Node* root, int target){
    if(root == NULL)
        return NULL;
    if(root->data == target)
        return root;
    Node* left = findTarget(root->left, target);
    if(left != NULL)
        return left;
    return findTarget(root->right, target);
}

bool isSubTree(Node* root1, Node* root2){
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    if(isSameTree(root1, root2))
        return true;
    return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
}