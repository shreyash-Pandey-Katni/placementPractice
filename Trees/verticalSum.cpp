#include<iostream>
#include<vector>
#include<map>

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

void verticalSumUtil(Node *node, int hd, map<int, int> &m){
    if(node == NULL)
        return;
    m[hd] += node->data;
    verticalSumUtil(node->left, hd - 1, m);
    verticalSumUtil(node->right, hd + 1, m);
}

vector<int> verticalSum(Node *root){
    map<int, int> m;
    verticalSumUtil(root, 0, m);
    vector<int> ans;
    for(auto it = m.begin(); it != m.end(); it++)
        ans.push_back(it->second);
    return ans;
}