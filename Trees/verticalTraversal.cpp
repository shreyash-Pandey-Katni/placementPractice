#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
unordered_map<int, vector<int>> temp;
int leftWidth = 0;
int rightWidth = 0;


void verticalOrderUtil(Node* root, int level){
    if(root == NULL)
        return;
    temp[level].push_back(root->data);
    leftWidth = min(leftWidth, level);
    rightWidth = max(rightWidth, level);
    verticalOrderUtil(root->left, level-1);
    verticalOrderUtil(root->right, level+1);
}
vector<int> verticalOrder(Node *root){
    temp.clear();
    leftWidth = 0;
    rightWidth = 0;
    verticalOrderUtil(root, 0);
    vector<int> ans;
    for(int i = leftWidth; i <= rightWidth; i++){
        for(int j = 0; j < temp[i].size(); j++){
            ans.push_back(temp[i][j]);
        }
    }
    return ans;
}