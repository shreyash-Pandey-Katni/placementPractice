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
vector<int> ans;
void ancestors(Node *root, vector<int> path, int target){
    if(root == NULL)
        return;
    if(root->data == target){
        ans = path;
        return;
    }
    path.push_back(root->data);
    ancestors(root->left, path, target);
    ancestors(root->right, path, target);
    path.pop_back();
}
vector<int> Ancestors(Node *root, int target){
    ans.clear();
    vector<int> path;
    ancestors(root, path, target);
    reverse(ans.begin(), ans.end());
    return ans;
}