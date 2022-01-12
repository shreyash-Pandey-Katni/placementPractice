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
int ans;
void getLevelUtil(Node *root, int level, int target){
    if(root == NULL)
        return;
    if(root->data == target){
        ans = level;
        return;
    }
    getLevelUtil(root->left, level+1, target);
    getLevelUtil(root->right, level+1, target);
}
int getLevel(Node *root, int target){
    ans = -1;
    getLevelUtil(root, 1, target);
    return ans;
}