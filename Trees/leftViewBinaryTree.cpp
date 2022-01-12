#include<iostream>
#include<vector>
#include<unordered_map>
#include<bits/stdc++.h>
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
vector<int> result;
void leftViewHelper(Node *root, int level){
    if(root == NULL)
        return;
    if(result.size() <= level)
        result.push_back(root->data);
    else
        result[level] = root->data;
    leftViewHelper(root->right, level + 1);
    leftViewHelper(root->left, level + 1);
}
vector<int> leftView(Node *root)
{
    if(root == NULL)
        return result;
    result.clear();
    leftViewHelper(root, 0);
    return result;
}