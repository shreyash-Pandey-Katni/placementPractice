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
vector<int> printNearNodes(Node* root, int low, int high){
    vector<int> res;
    if(root == NULL)
        return res;
    
    vector<int> left = printNearNodes(root->left, low, high);
    vector<int> right = printNearNodes(root->right, low, high);
    res.insert(res.end(), left.begin(), left.end());
    if (root->data >= low && root->data <= high)
    {
        res.push_back(root->data);
    }
    res.insert(res.end(), right.begin(), right.end());
    return res;
}