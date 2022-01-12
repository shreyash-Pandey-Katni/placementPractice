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
// vector<int> result;
vector<int> Kdistance(Node *root, int k)
{
    vector<int> result;
    if (root == NULL || k < 0)
        return result;
    if (k == 0)
    {
        result.push_back(root->data);
        return result;
    }
    vector<int> left = Kdistance(root->left, k - 1);
    vector<int> right = Kdistance(root->right, k - 1);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}