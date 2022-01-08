#include<iostream>
#include<vector>
#include<algorithm>
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

int height(Node *root)
{
    if(root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}