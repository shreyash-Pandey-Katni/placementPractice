#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    string data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
bool isLeaf(node *root){
    if(root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}

int solve(string operation, int val1, int val2){
    if(operation == "+")
        return val1 + val2;
    else if(operation == "-")
        return val1 - val2;
    else if(operation == "*")
        return val1 * val2;
    else if(operation == "/")
        return val1 / val2;
    else
        return 0;
}

int evalTree(node *root){
    if(root == NULL)
        return 0;
    if(isLeaf(root))
        return stoi(root->data);
    int left = evalTree(root->left);
    int right = evalTree(root->right);
    return solve(root->data, left, right);
}