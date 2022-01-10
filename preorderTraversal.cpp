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
vector<int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    ans.push_back(root->data);
    vector<int> left = preorder(root->left);
    vector<int> right = preorder(root->right);
    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}