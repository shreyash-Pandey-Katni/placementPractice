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

vector<int> inOrder(Node *root)
{
    vector<int> v;
    if(root == NULL)
        return v;
    // v.push_back(root->data);
    vector<int> left = inOrder(root->left);
    vector<int> right = inOrder(root->right);
    v.insert(v.end(), left.begin(), left.end());
    v.push_back(root->data);
    v.insert(v.end(), right.begin(), right.end());
    return v;
}