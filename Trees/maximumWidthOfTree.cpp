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
int maxWidth = INT_MIN;
unordered_map<int, int> ht;

void getMaxWidthUtil(Node *root, int level){
    if(root == NULL)
        return;
    if(ht.find(level) == ht.end())
        ht[level] = 1;
    else
        ht[level]++;
    maxWidth = max(maxWidth, ht[level]);
    getMaxWidthUtil(root->left, level + 1);
    getMaxWidthUtil(root->right, level+1);
}

int getMaxWidth(Node *root)
{
    if(root == NULL)
        return 0;
    maxWidth = INT_MIN;
    getMaxWidthUtil(root, 0);
    return maxWidth;
}