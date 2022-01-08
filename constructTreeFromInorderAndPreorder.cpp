#include<iostream>
#include<vector>
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
Node* buildTree(int in[], int pre[], int n){
    if(n == 0)
        return NULL;
    Node *root = new Node(pre[0]);
    int i;
    for(i = 0; i < n; i++)
        if(in[i] == pre[0])
            break;
    int left_size = i;
    int right_size = n - left_size - 1;
    root->left = buildTree(in, pre + 1, left_size);
    root->right = buildTree(in + left_size + 1, pre + left_size + 1, right_size);
    return root;
}