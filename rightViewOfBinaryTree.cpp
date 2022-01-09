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

unordered_map<int,int> levelMap;

void rightViewUtil(Node *root, int level)
{
    if(root == NULL)
        return;
    // if(levelMap.find(level) == levelMap.end())
        levelMap[level] = root->data;
    rightViewUtil(root->left, level+1);

    rightViewUtil(root->right, level + 1);
}

vector<int> rightView(Node *root){
    levelMap.clear();
    if(root == NULL){
        return vector<int>();
    }
    rightViewUtil(root, 0);
    vector<int> result;
    // int i = 0;
    for (int i = levelMap.size();i>=0;i--)
    {
        result.push_back(levelMap[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}