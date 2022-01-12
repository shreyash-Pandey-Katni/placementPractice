#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
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
int ans = INT_MIN;
bool isLeaf(Node *root)
{
    if (root == NULL)
        return false;
    return root->left == NULL && root->right == NULL;
}

int maxPathSumUtil(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (isLeaf(root))
    {
        return root->data;
    }
    int left = maxPathSumUtil(root->left);
    int right = maxPathSumUtil(root->right);
    if (root->left != NULL && root->right != NULL)
    {
        ans = max(root->data + left + right, ans);
        return root->data + max(left, right);
    }
    return root->left?root->data+left:root->data+right;
}

int maxPathSum(Node *root)
{
    ans = INT_MIN;
    maxPathSumUtil(root);
    return ans;
}