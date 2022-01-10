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
bool isLeaf(Node *root){
    if(root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}
vector<string> temp;
void treePathSumUtil(Node* root, string path){
    if(root == NULL)
        return;
    path += to_string(root->data);
    if(isLeaf(root)){
        temp.push_back(path);
        return;
    }
    treePathSumUtil(root->left, path);
    treePathSumUtil(root->right, path);
}
long long treePathsSum(Node *root){
    temp.clear();
    treePathSumUtil(root, "");
    long long sum = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        sum += stoll(temp[i]);
    }
    return sum;
}
