#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node *buildTree(int in[], int post[], int n){
    if(n==0)
        return NULL;
    int rootData = post[n-1];
    Node *root = new Node(rootData);
    int i;
    for(i=0; i<n; i++)
    {
        if(in[i] == rootData)
            break;
    }
    int leftSize = i;
    int rightSize = n-1-i;
    root->left = buildTree(in, post, leftSize);
    root->right = buildTree(in+leftSize+1, post+leftSize, rightSize);
    return root;
}