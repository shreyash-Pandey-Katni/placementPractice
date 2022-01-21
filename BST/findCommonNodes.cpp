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

unordered_map<int, int> temp;
// vector<int> ans;

void inorder(Node *root){
    if(root == NULL)
        return;
    inorder(root->left);
    temp[root->data] = 1;
    inorder(root->right);
}

vector<int> commonNodes(Node* root){
    if(root == NULL)
        return vector<int>();
    vector<int> left = commonNodes(root->left);
    vector<int> right = commonNodes(root->right);
    vector<int> ans;
    ans.insert(ans.end(), left.begin(), left.end());
    if(temp.find(root->data) != temp.end())
        ans.push_back(root->data);
    ans.insert(ans.end(), right.begin(), right.end());
    return ans;
}

vector<int>findCommon(Node* root1, Node* root2){
    temp.clear();
    inorder(root1);
    vector<int>res;
    res = commonNodes(root2);
    return res;
}